#include "raylib.h"
#include "raymath.h"

#include "playerController.h"
#include "options.h"
#include "groundController.h"
#include "pipeController.h"

int main() {
    
    playerController P = InitPlayerController();

    groundController G = InitGroundController();
    ceilingController C = InitCeilingController();
    pipeList p = InitPipeList();

    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Raylib Flappy Bird");
    SetTargetFPS(TARGET_FPS);

    while(!WindowShouldClose()) {
        BeginDrawing();
        // DRAW BG
        ClearBackground(RAYWHITE);

        // PLAYER
        calcPlayerPos(&P, &G, &C);
        drawPlayer(P);

        // PIPES
        MovePipeList(&p);
        DrawPipeList(&p);

        // CEILING + GROUND
        drawCeiling_Ground(G, C);

        // FPS
        DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}