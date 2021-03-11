#include <chrono>

#pragma once
class EngineStatics
{
private:
	static float DeltaTime;
	static float CurrentFPS;
	static double ElapsedTime;



public:
	/// <summary>
	/// This Gets DeltaTime, the time since last frame.
	/// </summary>
	/// <returns>Deltatime as a float</returns>
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
	static void UpdateStatics();
};

