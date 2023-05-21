#ifndef GROUND_CONTROLLER
#define GROUND_CONTROLLER
#include "raylib.h"
#include "options.h"

typedef struct {
    
    int posY;
    Rectangle ground;

} groundController;

typedef struct {

    int posY;
    Rectangle ceiling;

} ceilingController;

void drawCeiling_Ground(groundController G, ceilingController C) {

    DrawRectangleRec(G.ground, CEILING_GROUND_COL);
    DrawRectangleRec(C.ceiling, CEILING_GROUND_COL);
    DrawLine(0,CEILING_HEIGHT,SCREEN_WIDTH,CEILING_HEIGHT,GRAY);
    DrawLine(0,GROUND_HEIGHT,SCREEN_WIDTH,GROUND_HEIGHT,GRAY);

}

groundController InitGroundController() {
    groundController G;
    G.posY = GROUND_HEIGHT;
    G.ground.x = 0;
    G.ground.y = G.posY;
    G.ground.height = CEILING_HEIGHT;
    G.ground.width = SCREEN_WIDTH; 
    return G;   
}

ceilingController InitCeilingController() {
    ceilingController C;
    C.posY = CEILING_HEIGHT;
    C.ceiling.x = 0;
    C.ceiling.y = 0;
    C.ceiling.height = CEILING_HEIGHT;
    C.ceiling.width = SCREEN_WIDTH;
    return C;   
}

#endif