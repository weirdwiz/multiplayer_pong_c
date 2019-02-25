#include "draw.h"

void prepareScene(void)
{
    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
    SDL_RenderPresent(app.renderer);
}

void drawRectangle(SDL_Rect *rect, Uint8 r, Uint8 g, Uint8 b)
{
    // Set render color
    SDL_SetRenderDrawColor(app.renderer, r, g, b, 255);

    // Render rect
    SDL_RenderFillRect(app.renderer, rect);
}

void drawEntity(Entity e)
{
    drawRectangle(&e.rect, e.r, e.g, e.b);
}
