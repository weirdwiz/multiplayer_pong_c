#include "common.h"

extern void cleanup(void);
extern void initSDL(void);
extern void prepareScene(void);
extern void presentScene(void);
extern void doInput(void);
extern void drawEntity(Object e);
extern void drawBall(Ball e);
extern void drawRectangle(SDL_Rect *rect, Uint8 r, Uint8 g, Uint8 b);
App app;
Object player1;
Object player2;
Ball ball;
