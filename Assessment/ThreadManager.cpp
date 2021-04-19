#include "ThreadManager.h"


ThreadManager::~ThreadManager()
{
    m_isDeconstructing = true;
    m_isInitialized = false;

    m_scheduleList.clear();
    m_guidsToCancel.clear();
    m_threadList.clear();
}

void ThreadManager::Monitor()
{
    while (!m_isDeconstructing)
    {
        // Clean up m_threadList.
        std::unordered_set<GUID> toRemove;
        for (std::pair<GUID, std::thread*> value : m_threadList)
        {
            if (value.second->joinable())
            {
                toRemove.insert(value.first);
            }
        }

        for (GUID value : toRemove)
        {
            m_threadList.erase(value);
        }

        // Clean up m_guidsToCancel
        for (GUID value : m_guidsToCancel)
        {
            // Because we cleaned up thread list of dead threads, we can remove them from GUID's to cancel list.
            if (m_threadList.find(value) == m_threadList.end())
            {
                m_threadList.erase(value);
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void ThreadManager::Initialize()
{
    std::thread(Monitor);
    m_isInitialized = true;
}

void ThreadManager::InitializeIfNotInitialized()
{
    if (!m_isInitialized)
    {
        ThreadManager::Initialize();
    }
}

void ThreadManager::Run(GUID guid)
{
    ThreadManager::InitializeIfNotInitialized();
    m_threadList.insert(std::make_pair(guid, new std::thread(m_scheduleList.find(guid))));
    m_scheduleList.erase(guid);
}

GUID& ThreadManager::Schedule(std::function<void()> const func)
{
    ThreadManager::InitializeIfNotInitialized();
    GUID guid;
    CoCreateGuid(&guid);

    m_scheduleList.insert(std::make_pair(guid, func));

    return guid;
}

void ThreadManager::Stop(GUID guid)
{
    ThreadManager::InitializeIfNotInitialized();
    if (m_scheduleList.find(guid) != m_scheduleList.end())
    {
        m_scheduleList.erase(guid);
    }

    if (m_threadList.find(guid) != m_threadList.end())
    {
        m_guidsToCancel.insert(guid);
        m_threadList.erase(guid);
    }
}

template<typename ...GUID>
void ThreadManager::Stop(const GUID & ...guids)
{
    ThreadManager::InitializeIfNotInitialized();
    std::unordered_set<GUID&> guids = { ...guids };
    for (unsigned i = 0; i < guids.size(); i++)
    {
        ThreadManager::Stop(guids[i]);
    }

}

void ThreadManager::StopAll()
{
    ThreadManager::InitializeIfNotInitialized();
    m_scheduleList.clear();
    std::unordered_map<GUID, std::thread*> threadListCopy = m_threadList;
    for (std::pair<GUID, std::thread*> value : threadListCopy)
    {
        ThreadManager::Stop(value.first);
    }
}

void ThreadManager::Wait(GUID guid)
{
    ThreadManager::InitializeIfNotInitialized();
    std::thread* thread = m_threadList[guid];
    while (thread->joinable())
    {
        // Thread is still running, continue blocking.
    }
}

bool ThreadManager::IsCancellationRequested(std::thread* thread)
{
    ThreadManager::InitializeIfNotInitialized();
    GUID targetGuid;

    for (std::pair<GUID, std::thread*> value : m_threadList)
    {
        if (value.second == thread)
        {
            targetGuid = value.first;
            break;
        }
    }

    return m_guidsToCancel.count(targetGuid);
}

template<typename ...GUID>
void ThreadManager::Wait(const GUID & ...guids)
{
    ThreadManager::InitializeIfNotInitialized();
    std::unordered_set<GUID&> guids = { ...guids };
    for (unsigned i = 0; i < guids.size(); i++)
    {
        // This will block the current thread until said thread is complete.
        ThreadManager::Wait(m_threadList[guids[i]]);
    }
}