#include "Camera.h"

void Camera::setViewPortX(float viewportx)
{
	// with these you would then do setViewPortX(m_pot_x_pos - m_x_pos); when you move the character,in input perhaps, update the potential position //

	if (viewportX + viewportx < 0)
	{
		viewportX = 0;
	}
	else
	{
		viewportX += viewportx;
	}

	viewport.x = viewportX;
	SDL_RenderSetViewport(Renderer::renderer, &viewport);
}

void Camera::setViewPortY(float viewporty)
{
	viewportY += viewporty;

	viewport.y = viewportY;
	SDL_RenderSetViewport(Renderer::renderer, &viewport);
}

void Camera::CameraFunctionality(float valueX, float valueY)
{
	//find the movement direction and then set the correct viewport from this
	
	setViewPortX(valueX);
	
	setViewPortY(valueY);
	
}