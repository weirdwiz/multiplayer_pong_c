#include "SDL2/SDL.h"

typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
  int up;
  int down;
  int w;
  int s;
} App;

typedef struct {
  // Rectangle
  SDL_Rect rect;
  // Color
  Uint8 r, g, b;
} Object;

typedef struct {
  SDL_Rect rect;
  int x_vel, y_vel;
  Uint8 r, g, b;
} Ball;