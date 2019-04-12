#include "main.h"

int main(int argc, char *argv[]) {
  srand(time(0));

  // idk what is this, just go along
  memset(&app, 0, sizeof(App));
  memset(&player1, 0, sizeof(Object));
  memset(&player2, 0, sizeof(Object));
  memset(&ball, 0, sizeof(Ball));

  player1.rect.x = 30;                        // x coordinate of rectangle
  player1.rect.y = (SCREEN_HEIGHT - 100) / 2; // y coordinate of rectange
  player1.rect.h = 100;                       // height of the rectangle
  player1.rect.w = 20;                        // width of the rectangle
  // color value for RGB
  player1.r = 255;
  player1.g = 0;
  player1.b = 0;

  player2.rect.x = 950;                       // x coordinate of rectangle
  player2.rect.y = (SCREEN_HEIGHT - 100) / 2; // y coordinate of rectange
  player2.rect.h = 100;                       // height of the rectangle
  player2.rect.w = 20;                        // width of the rectangle
  // color value for RGB
  player2.r = 0;
  player2.g = 0;
  player2.b = 255;

  int start_ball = (rand() % (SCREEN_HEIGHT - 0 + 1));
  ball.rect.x = SCREEN_WIDTH / 2;
  ball.rect.y = start_ball;
  ball.rect.h = 20;
  ball.rect.w = 20;
  ball.r = 255;
  ball.b = 0;
  ball.g = 255;

  ball.x_vel = 8;
  ball.y_vel = 8;

  initSDL();       // Intialise
  atexit(cleanup); // Destroy stuff

  drawBall(ball);
  drawEntity(player1);
  drawEntity(player2);
  presentScene();

  SDL_Delay(3000);

  while (1) {
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

    // if (ball.rect.x + ball.rect.w >= SCREEN_WIDTH || ball.rect.x <= 0) {
    //   ball.x_vel = -ball.x_vel;
    // }

    // checks the boundary conditions, so that the ball can bounce
    if (ball.rect.y + ball.rect.h >= SCREEN_HEIGHT || ball.rect.y <= 0) {
      ball.y_vel = -ball.y_vel;
    }

    // checks if the ball hit's player 1's paddle
    if (ball.rect.x <= player1.rect.x + player1.rect.w &&
        (ball.rect.y + ball.rect.w >= player1.rect.y &&
         ball.rect.y <= player1.rect.y + player1.rect.h)) {
      ball.x_vel = -ball.x_vel;
    }

    // checks if the ball hit's player 2's paddle
    if (ball.rect.x + ball.rect.w >= player2.rect.x &&
        (ball.rect.y + ball.rect.w >= player2.rect.y &&
         ball.rect.y <= player2.rect.y + player2.rect.h)) {
      ball.x_vel = -ball.x_vel;
    }

    // if the ball touches the vertical walls the game ends
    if (ball.rect.x + ball.rect.w >= SCREEN_WIDTH || ball.rect.x <= 0) {
      break;
    }

    drawBall(ball);
    drawEntity(player1);
    drawEntity(player2);
    presentScene();
    SDL_Delay(16);
  }
  return 0;
}
