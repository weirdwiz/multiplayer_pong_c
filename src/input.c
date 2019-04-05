#include "input.h"

void doKeyDown(SDL_KeyboardEvent *event)
{
    if (event->repeat == 0)
    {
        if (event->keysym.scancode == SDL_SCANCODE_UP)
        {
            app.up = 1;
        }
        if (event->keysym.scancode == SDL_SCANCODE_DOWN)
        {
            app.down = 1;
        }
    }
}

void doKeyUp(SDL_KeyboardEvent *event)
{
    if (event->repeat == 0)
    {
        if (event->keysym.scancode == SDL_SCANCODE_UP)
        {
            app.up = 0;
        }
        if (event->keysym.scancode == SDL_SCANCODE_DOWN)
        {
            app.down = 0;
        }
    }
}

//
void doKeyDown2(SDL_KeyboardEvent *event)
{
    if (event->repeat == 0)
    {
        if (event->keysym.scancode == SDL_SCANCODE_W)
        {
            app.up = 1;
        }
        if (event->keysym.scancode == SDL_SCANCODE_S)
        {
            app.down = 1;
        }
    }
}

void doKeyUp2(SDL_KeyboardEvent *event)
{
    if (event->repeat == 0)
    {
        if (event->keysym.scancode == SDL_SCANCODE_W)
        {
            app.up = 0;
        }
        if (event->keysym.scancode == SDL_SCANCODE_S)
        {
            app.down = 0;
        }
    }
}


//
void doInput(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            exit(0);
            break;

        case SDL_KEYDOWN:
            doKeyDown(&event.key);
            doKeyDown2(&event.key);
            break;

        case SDL_KEYUP:
            doKeyUp(&event.key);
            doKeyUp2(&event.key);
            break;
        default:
            break;
        }
    }
}