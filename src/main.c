#include "main.h"

int main(int argc, char *argv[])
{
    // idk what this, is just go along
    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));

    player.rect.x = 50;
    player.rect.y = 10;
    player.rect.h = 100;
    player.rect.w = 20;
    player.r = 255;
    player.g = 255;
    player.b = 255;

    initSDL();       // Intialise
    atexit(cleanup); // Destroy stuff

    while (1)
    {
        prepareScene();
        doInput();

        if (app.up && (player.rect.y) >= 0)
        {
            player.rect.y -= 10;
        }
        if (app.down && (player.rect.y + 100) <= SCREEN_HEIGHT)
        {
            player.rect.y += 10;
        }

        drawEntity(player);
        presentScene();
        SDL_Delay(16);
    }
    return 0;
}