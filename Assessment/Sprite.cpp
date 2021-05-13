#include "Sprite.h"
#include "ImageLoader.h"

// changed
// san 10/03/21

Sprite::Sprite()
{

}
Sprite::Sprite(SDL_Texture* text)
{
	sprite = text;
}


//Animation
Sprite::Sprite(SDL_Texture* text, bool isAnimated, int width, int height)
{
	animated = isAnimated;
	SourceRect.x = SourceRect.y = 0;
	SourceRect.w = width;
	SourceRect.h = height;
	DestRect.w = 128;
	DestRect.h = 128;

	//Creating Animations
	Animation Idle = Animation(0, 3, 100);// columns, row, speed

	//Puts in the actual animation
	anims.emplace("Idle", Idle);

	//playing an animation
	PlayAnimation("Idle");// example
    sprite = text;
}
//Animation



Vector2 Sprite::getPos()
{
    return pos;
}

void Sprite::setPos(Vector2 newPos)
{
    pos = newPos;
}

/// <summary>
/// Returns sprite for map-loader - CW
/// </summary>
SDL_Texture* Sprite::GetSprite()
{
	return sprite;
}



//Animation
void Sprite::PlayAnimation(const char* AnimName)
{
	//Finds animation put in and returns appropraite information
	frames = anims[AnimName].Frames;
	AnimIndex = anims[AnimName].Index;
	speed = anims[AnimName].Speed;
}
void Sprite::SpriteUpdate(int cameraX, int cameraY, int width, int height)
{
	if (animated)
	{
		SourceRect.x = SourceRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);// ticks through spritesheet
	}

	//follows the players position and scale
	SourceRect.y = AnimIndex * SourceRect.h; //when not animated , animation index is zero
	DestRect.x = pos.x - cameraX;//200; //PLAYERS POSITION x
	DestRect.y = pos.y - cameraY;//200; //Players Position y
	DestRect.w = width;//width * Scale; //
	DestRect.h = height;//heigh * Scale; //

}

void Sprite::Draw()
{
	//SDL_RenderCopy(Renderer::renderer, sprite, NULL, &DestRect);
	SDL_RenderCopyEx(Renderer::renderer, sprite, &SourceRect, &DestRect, NULL, NULL, FlipMode); //can flip animation depending on direction
}
//Animation

