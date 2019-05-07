#include "main.h"
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
  srand(time(0));

  int count = 3;

  // idk what is this, just go along
  memset(&app, 0, sizeof(App));
  memset(&player1, 0, sizeof(Object));
  memset(&player2, 0, sizeof(Object));
  memset(&ball, 0, sizeof(Ball));

  initSDL();
  initPlayers();
  atexit(cleanup); // Destroy stuff
  draw();
  presentScene();
  SDL_Delay(3000);

  while (count > 0) {
    prepareScene();
    doInput();
    // controls for player 1
    // up
    if (app.w && (player1.rect.y - 10) >= 0) {
      player1.rect.y -= 10;
    }
    // down
    if (app.s && (player1.rect.y + player1.rect.h + 30) <= SCREEN_HEIGHT) {
      player1.rect.y += 10;
    }

    // controls for player 2
    // up
    if (app.up && (player2.rect.y - 10) >= 0) {
      player2.rect.y -= 10;
    }
    // down
    if (app.down && (player2.rect.y + player2.rect.h + 30) <= SCREEN_HEIGHT) {
      player2.rect.y += 10;
    }

    ball.rect.x += ball.x_vel;
    ball.rect.y += ball.y_vel;

    checkCollision();

    // if the ball touches the vertical walls the game ends
    if (ball.rect.x - ball.rect.w >= SCREEN_WIDTH) {
        player1.Score++;    
        ball.rect.x = SCREEN_WIDTH/2;
        ball.rect.y = (rand() % (SCREEN_HEIGHT - 0 + 1));
        count--;
        prepareScene();
        draw();
        presentScene();
        SDL_Delay(1000);
    } 
    else if(ball.rect.x + ball.rect.w <= 0) {
        player2.Score++;
        ball.rect.x = SCREEN_WIDTH/2;
        ball.rect.y = (rand() % (SCREEN_HEIGHT - 0 + 1));
        count--;
        prepareScene();
        draw();
        presentScene();
        SDL_Delay(1000);
    }
    draw();
    presentScene();
    SDL_Delay(16);
  }
  printf("Player 1: %d\n",player1.Score);
  printf("Player 2: %d\n",player2.Score);
  return 0;
}
