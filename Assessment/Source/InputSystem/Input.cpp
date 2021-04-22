#include "Input.h"
#include <iostream>

Input::Input()
{
    for (int i = 0; i < SIZEOF_KEY_LIST; i++)
    {
        keysPressed[i] = false;
    }
}

Input::~Input()
{
}

bool Input::keysPressed[SIZEOF_KEY_LIST];

SDL_Event Input::inputEvent;

void Input::UpdateInstance()
{
    while (SDL_PollEvent(&inputEvent) != NULL)
    {
        if (inputEvent.type == SDL_KEYDOWN)
        {
            SDL_Keycode pressed = inputEvent.key.keysym.sym;

            switch (pressed)
            {
            case SDLK_ESCAPE:
                keysPressed[KEY_ESC] = true;
                break;
            case SDLK_w: case SDLK_UP:
                keysPressed[KEY_UP] = true;
                break;
            case SDLK_a: case SDLK_LEFT:
                keysPressed[KEY_LEFT] = true;
                break;
            case SDLK_s: case SDLK_DOWN:
                keysPressed[KEY_DOWN] = true;
                break;
            case SDLK_d: case SDLK_RIGHT:
                keysPressed[KEY_RIGHT] = true;
                break;
            case SDLK_SPACE:
                keysPressed[KEY_SPACE] = true;
                break;
            case SDLK_LSHIFT:
                keysPressed[KEY_LSHIFT] = true;
                break;
            default:
                break;
            }

#ifdef _DEBUG
            std::cout << ("Key Pressed: %s", (char)pressed);
#endif // _DEBUG

        }
        if (inputEvent.type == SDL_KEYUP)
        {
            SDL_Keycode pressed = inputEvent.key.keysym.sym;

            switch (pressed)
            {
            case SDLK_ESCAPE:
                keysPressed[KEY_ESC] = false;
                break;
            case SDLK_w: case SDLK_UP:
                keysPressed[KEY_UP] = false;
                break;
            case SDLK_a: case SDLK_LEFT:
                keysPressed[KEY_LEFT] = false;
                break;
            case SDLK_s: case SDLK_DOWN:
                keysPressed[KEY_DOWN] = false;
                break;
            case SDLK_d: case SDLK_RIGHT:
                keysPressed[KEY_RIGHT] = false;
                break;
            case SDLK_SPACE:
                keysPressed[KEY_SPACE] = false;
                break;
            case SDLK_LSHIFT:
                keysPressed[KEY_LSHIFT] = false;
                break;
            default:
                break;
            }
#ifdef DEBUG
            std::cout << ("Key Pressed: %s", (char)pressed);
#endif // _DEBUG
        }
    }
}

void Input::Update()
{
    while (SDL_PollEvent(&inputEvent) != NULL)
    {
        if (inputEvent.type == SDL_KEYDOWN)
        {
            SDL_Keycode pressed = inputEvent.key.keysym.sym;

            switch (pressed)
            {
            case SDLK_ESCAPE:
                keysPressed[KEY_ESC] = true;
                break;
            case SDLK_w: case SDLK_UP:
                keysPressed[KEY_UP] = true;
                break;
            case SDLK_a: case SDLK_LEFT:
                keysPressed[KEY_LEFT] = true;
                break;
            case SDLK_s: case SDLK_DOWN:
                keysPressed[KEY_DOWN] = true;
                break;
            case SDLK_d: case SDLK_RIGHT:
                keysPressed[KEY_RIGHT] = true;
                break;
            case SDLK_SPACE:
                keysPressed[KEY_SPACE] = true;
                break;
            case SDLK_LSHIFT:
                keysPressed[KEY_LSHIFT] = true;
                break;
            default:
                break;
            }

#ifdef _DEBUG
            std::cout << ("Key Pressed: %s", (char)pressed);
#endif // _DEBUG

        }
        if (inputEvent.type == SDL_KEYUP)
        {
            SDL_Keycode pressed = inputEvent.key.keysym.sym;

            switch (pressed)
            {
            case SDLK_ESCAPE:
                keysPressed[KEY_ESC] = false;
                break;
            case SDLK_w: case SDLK_UP:
                keysPressed[KEY_UP] = false;
                break;
            case SDLK_a: case SDLK_LEFT:
                keysPressed[KEY_LEFT] = false;
                break;
            case SDLK_s: case SDLK_DOWN:
                keysPressed[KEY_DOWN] = false;
                break;
            case SDLK_d: case SDLK_RIGHT:
                keysPressed[KEY_RIGHT] = false;
                break;
            case SDLK_SPACE:
                keysPressed[KEY_SPACE] = false;
                break;
            case SDLK_LSHIFT:
                keysPressed[KEY_LSHIFT] = false;
                break;
            default:
                break;
            }
#ifdef DEBUG
            std::cout << ("Key Pressed: %s", (char)pressed);
#endif // _DEBUG
        }
    }
}

bool Input::KeyIsDown(KEY_LIST key)
{
    return keysPressed[key];
}
