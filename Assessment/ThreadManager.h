#ifndef THREAD_MANAGER_H_
#define THREAD_MANAGER_H_

#include <functional>
#include <thread>
#include <unordered_set>
#include <unordered_map>
#include <Windows.h>

/// <summary>
///		ThreadManager is responsible for delegating work to their own threads
///		and storing their data if a need araises to cancel.
/// 
///		Work can also be scheduled and run in another place which allows the
///		user to simply pass down a GUID rather than various parameters.
/// </summary>
static class ThreadManager
{
private:
	~ThreadManager();

	/// <summary>
	/// Every one second we will clear up m_threadList and m_guidsToCancel
	/// by checking if their execution has finished.
	/// </summary>
	static void Monitor();

	/// <summary>
	/// Starts up the Monitor on a new fire & forget thread.
	/// </summary>
	static void Initialize();

	/// <summary>
	/// Checks if ThreadManager has been initialized, and if not it'll initialize.
	/// </summary>
	static void InitializeIfNotInitialized();

	/// <summary>
	/// Set to true when ThreadManager has been initialized.
	/// </summary>
	static bool m_isInitialized;

	/// <summary>
	/// Set to true when the deconstructor has been called.
	/// This will stop the monitor thread.
	/// </summary>
	/// <param name="guid"></param>
	static bool m_isDeconstructing;

	/// <summary>
	/// List of the currently running threads.
	/// </summary>
	static std::unordered_map<GUID, std::thread*> m_threadList;

	/// <summary>
	/// List of threads that can be run.
	/// </summary>
	static std::unordered_map<GUID, std::function<void()> const> m_scheduleList;

	/// <summary>
	/// List of GUID's which should be cancelled.
	/// </summary>
	static std::unordered_set<GUID> m_guidsToCancel;

public:
	/// <summary>
	///		Start the execution of thread.
	/// </summary>
	/// <param name="guid">Job to run.</param>
	static void Run(GUID guid);

	/// <summary>
	///		Creates new thread that will await execution.
	/// </summary>
	/// <param name="func">Function that will be executed.</param>
	/// <returns>GUID assigned to the job.</returns>
	static GUID& Schedule(std::function<void()> const func);

	/// <summary>
	///		Stop a thread instantly.
	///		This will also cancel any work that was scheduled.
	/// </summary>
	/// <param name="guid">Which job to cancel.</param>
	static void Stop(GUID guid);

	/// <summary>
	///		Stops threads instantly.
	///		This will also cancel any work that was scheduled.
	/// </summary>
	/// <typeparam name="...GUID">Pack parameter of GUID's.</typeparam>
	/// <param name="...guids">GUID's to stop.</param>
	template<typename ... GUID>
	static void Stop(const GUID&... guids);

	/// <summary>
	///		Stops all running jobs and also cancels any scheduled ones.
	/// </summary>
	static void StopAll();

	/// <summary>
	///		Waits until the target job is complete.
	///		This will block the thread executing the method until complete.
	/// </summary>
	static void Wait(GUID guid);

	/// <summary>
	///		Waits until all the target jobs are complete.
	///		This will block the thread executing the method until complete.
	/// </summary>
	/// <typeparam name="...GUID">Pack parameter of GUID's.</typeparam>
	/// <param name="...guids">GUID's to wait for completion of.</param>
	template<typename ... GUID>
	static void Wait(const GUID&... guids);

	/// <summary>
	///		Checks if the thread should terminate itself.
	/// </summary>
	/// <param name="thread">The thread to check for cancellation.</param>
	/// <returns>If cancellation should occur.</returns>
	static bool IsCancellationRequested(std::thread* thread);
};

#endif
