#include "SDL2/SDL.h"

typedef struct
{
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

typedef struct
{
    // Rectangle
    SDL_Rect rect;
    // Color
    Uint8 r, g, b;
} Entity;