#include <chrono>

#pragma once
class EngineStatics
{
private:
	static float deltaTime;
	static float currentFPS;
	static double elapsedTime;

	//Time Stuff
	std::chrono::time_point<std::chrono::high_resolution_clock> thisFrameTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> lastFrameTime;


public:
	/// <summary>
	/// This Gets DeltaTime, the time since last frame in Milliseconds
	/// </summary>
	/// <returns>Deltatime(ms) as a float</returns>
	static float GetDeltaTime();

	/// <summary>
	/// This Gets the current FPS.
	/// </summary>
	/// <returns>FPS as a float</returns>
	static float GetCurrentFPS();

	/// <summary>
	/// This returns how long the program has been running.
	/// </summary>
	/// <returns>Time since game started, as double</returns>
	static double GetElapsedTime();

	/// <summary>
	/// Updates All Statics, shouldn't be used outside of the main loop
	/// </summary>
	void UpdateStatics();
};

