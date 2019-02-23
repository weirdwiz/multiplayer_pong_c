#include "draw.h"

void prepareScene(void)
{
    SDL_SetRenderDrawColor(app.renderer, 92, 19, 123, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
    SDL_RenderPresent(app.renderer);
}
