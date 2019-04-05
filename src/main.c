#include "main.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int main(int argc, char *argv[])
{
    // idk what this, is just go along
    memset(&app, 0, sizeof(App));
    memset(&player1, 0, sizeof(Entity));
    memset(&player2, 0, sizeof(Entity));

    player1.rect.x = 30; // x coordinate of rectangle
    player1.rect.y = (SCREEN_HEIGHT-100)/2; // y coordinate of rectange
    player1.rect.h = 100; // height of the rectangle
    player1.rect.w = 20;  // width of the rectangle
    // color value for RGB
    player1.r = 255;     
    player1.g = 0;
    player1.b = 0;



    player2.rect.x = 950; // x coordinate of rectangle
    player2.rect.y = (SCREEN_HEIGHT-100)/2; // y coordinate of rectange
    player2.rect.h = 100; // height of the rectangle
    player2.rect.w = 20;  // width of the rectangle
    // color value for RGB
    player2.r = 0;     
    player2.g = 0;
    player2.b = 255;

    initSDL();       // Intialise
    atexit(cleanup); // Destroy stuff

    while (1)
    {
        prepareScene();
        doInput();
        //controls for player 1
        if (app.up && (player1.rect.y - 10) >= 0)
        {
            player1.rect.y -= 10;
        }
        if (app.down && (player1.rect.y + player1.rect.h + 30) <= SCREEN_HEIGHT)
        {
            player1.rect.y += 10;
        }
        
        //controls for player 2
        if (app.up && (player2.rect.y - 10) >= 0)
        {
            player2.rect.y -= 10;
        }
        if (app.down && (player2.rect.y + player2.rect.h + 30) <= SCREEN_HEIGHT)
        {
            player2.rect.y += 10;
        }
        

        drawEntity(player1);
        drawEntity(player2);
        presentScene();
        SDL_Delay(16);
    }
    return 0;
}
