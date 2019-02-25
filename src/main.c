#include "main.h"

int main(int argc, char *argv[])
{
    // idk what this is just go along
    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));
    player.rect.x = 10;
    player.rect.y = 10;
    player.rect.h = 100;
    player.rect.w = 10;
    player.r = 255;
    player.g = 255;
    player.b = 255;

    initSDL();       // Intialise
    atexit(cleanup); // Destroy stuff

    while (1)
    {
        prepareScene();
        doInput();
        drawEntity(player);
        presentScene();
        SDL_Delay(16);
    }
    return 0;
}