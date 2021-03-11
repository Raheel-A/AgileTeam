#include "EngineStatics.h"

float EngineStatics::deltaTime;
float EngineStatics::currentFPS;
double EngineStatics::elapsedTime;


float EngineStatics::GetDeltaTime()
{
    return deltaTime;
}

float EngineStatics::GetCurrentFPS()
{
    return currentFPS;
}

double EngineStatics::GetElapsedTime()
{
    return elapsedTime;
}

void EngineStatics::UpdateStatics()
{
    //Update Time Data and Delta Time
    lastFrameTime = thisFrameTime;

    thisFrameTime = std::chrono::steady_clock::now();
    deltaTime = std::chrono::duration<float, std::milli>(thisFrameTime - lastFrameTime).count();
    deltaTime = deltaTime / 1000;
    elapsedTime += deltaTime;
}
