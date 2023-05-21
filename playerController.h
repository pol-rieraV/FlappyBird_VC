#include "options.h"
#include "groundController.h"
#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    
    int posY;
    int posX;
    int size;
    int gravity;
    float speed;
    Rectangle player;

} playerController;

void drawPlayer(playerController P) {
    DrawRectangleRec(P.player, RED);
}

void setSpeed(playerController* a, int s) {
    if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        a->speed = PLAYER_JUMP;
    } else {
        a->speed -= PLAYER_GRAVITY * GetFrameTime();
    }
}

void calcPlayerPos(playerController* a, groundController* G, ceilingController* C) {

    if (CheckCollisionRecs(a->player, C->ceiling)) {
        a->speed = 0;
        a->player.y = C->posY;
    }

    setSpeed(a, 0);

    a->posY -= a->speed;
    a->player.y -= a->speed;

    if (CheckCollisionRecs(a->player, G->ground)) {
        a->speed= 0;
        a->player.y = G->ground.y - PLAYER_SIZE;
    }
}

playerController InitPlayerController() {
    playerController P;
    P.posX = PLAYER_POS_X;
    P.posY = PLAYER_POS_Y;
    P.size = PLAYER_SIZE;
    P.player.x = PLAYER_POS_X;
    P.player.y = PLAYER_POS_Y;
    P.player.height = PLAYER_SIZE;
    P.player.width = PLAYER_SIZE;
    return P;
}
