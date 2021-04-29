#pragma once
#include "Renderer.h"

class Camera
{
public:
	void CameraFunctionality(float valueX, float valueY);
	void setViewPortX(float viewportx);
	void setViewPortY(float viewporty);
	float viewportX = 0.0f;
	float viewportY = 0.0f;

protected:
	SDL_Rect viewport{ 0, 0, 1080, 1920 };
};

