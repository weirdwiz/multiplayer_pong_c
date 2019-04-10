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

void doInput(void) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      exit(0);
      break;

    case SDL_KEYDOWN:
      doKeyDown(&event.key);
      break;

    case SDL_KEYUP:
      doKeyUp(&event.key);
      break;

    default:
      break;
    }
  }
}