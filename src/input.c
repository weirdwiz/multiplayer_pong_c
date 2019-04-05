#include "input.h"

void doKeyDown(SDL_KeyboardEvent *event) {
  if (event->repeat == 0) {
    if (event->keysym.scancode == SDL_SCANCODE_UP) {
      app.up = 1;
    }
    if (event->keysym.scancode == SDL_SCANCODE_DOWN) {
      app.down = 1;
    }
    if (event->keysym.scancode == SDL_SCANCODE_W) {
      app.w = 1;
    }
    if (event->keysym.scancode == SDL_SCANCODE_S) {
      app.s = 1;
    }
  }
}

void doKeyUp(SDL_KeyboardEvent *event) {
  if (event->repeat == 0) {
    if (event->keysym.scancode == SDL_SCANCODE_UP) {
      app.up = 0;
    }
    if (event->keysym.scancode == SDL_SCANCODE_DOWN) {
      app.down = 0;
    }
    if (event->keysym.scancode == SDL_SCANCODE_W) {
      app.w = 0;
    }
    if (event->keysym.scancode == SDL_SCANCODE_S) {
      app.s = 0;
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
}

void checkCollision(void) {
  // checks the boundary conditions, so that the ball can bounce
  if (ball.rect.y + ball.rect.h >= SCREEN_HEIGHT || ball.rect.y <= 0) {
    ball.y_vel = -ball.y_vel;
  }

  // checks if the ball hit's player 1's paddle
  if (ball.rect.x <= player1.rect.x + player1.rect.w &&
      (ball.rect.y + ball.rect.h >= player1.rect.y &&
       ball.rect.y + ball.rect.h <= player1.rect.y + player1.rect.h)) {
    ball.x_vel = -ball.x_vel;
  }

  // checks if the ball hit's player 2's paddle
  if (ball.rect.x + ball.rect.w >= player2.rect.x &&
      (ball.rect.y + ball.rect.h >= player2.rect.y &&
       ball.rect.y + ball.rect.h <= player2.rect.y + player2.rect.h)) {
    ball.x_vel = -ball.x_vel;
  }

  if ((ball.rect.x <= player1.rect.x + player1.rect.w &&
       ball.rect.x >= player1.rect.x) ||
      (ball.rect.x + ball.rect.w <= player1.rect.x + player1.rect.w &&
       ball.rect.x + ball.rect.w >= player1.rect.x)) {
    if (ball.rect.y + ball.rect.h == player1.rect.y ||
        ball.rect.y == player1.rect.y + player1.rect.h) {
      ball.y_vel = -ball.y_vel;
      ball.x_vel = -ball.x_vel;
    }
  }

  if ((ball.rect.x + ball.rect.w >= player2.rect.x &&
       ball.rect.x + ball.rect.w <= player2.rect.x + player2.rect.w) ||
      (ball.rect.x >= player2.rect.x &&
       ball.rect.x <= player2.rect.x + player2.rect.w)) {
    if (ball.rect.y + ball.rect.h <= player2.rect.y &&
            ball.rect.y >= player2.rect.y + player2.rect.h ||
        ball.rect.y == player2.rect.y + player2.rect.h) {
      ball.y_vel = -ball.y_vel;
      ball.x_vel = -ball.x_vel;
    }
  }
}