#include "init.h"

void initSDL(void) {
  int rendererFlags, windowFlags;
  rendererFlags = SDL_RENDERER_ACCELERATED;
  windowFlags = 0;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Couldn't initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }

  app.window =
      SDL_CreateWindow("PONG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

  if (!app.renderer) {
    printf("Failed to create renderer: %s\n", SDL_GetError());
    exit(1);
  }
}

void cleanup(void) {
  SDL_DestroyRenderer(app.renderer);
  SDL_DestroyWindow(app.window);
  SDL_Quit();
}

void initPlayers(void) {
  player1.rect.x = 0;                         // x coordinate of rectangle
  player1.rect.y = (SCREEN_HEIGHT - 100) / 2; // y coordinate of rectange
  player1.rect.h = 100;                       // height of the rectangle
  player1.rect.w = 20;                        // width of the rectangle

  // color value for RGB
  player1.r = 255;
  player1.g = 0;
  player1.b = 0;

  player2.rect.x = 980;                       // x coordinate of rectangle
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
}