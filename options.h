#ifndef options
#define options
#include "raylib.h"

//SCREEN OPTIONS -- -- -- --
#define SCREEN_WIDTH        650
#define SCREEN_HEIGHT       400
#define TARGET_FPS          70

//PLAYER OPTIONS -- -- -- --
#define PLAYER_SIZE         25
#define PLAYER_POS_X        110
#define PLAYER_POS_Y        SCREEN_HEIGHT/2 - PLAYER_SIZE/2
#define PLAYER_GRAVITY      10
#define PLAYER_JUMP         5.25
#define PLAYER_COLOR        GRAY

// PIPE OPTIONS -- -- -- --
#define PIPE_MIN_HEIGHT     SCREEN_HEIGHT - 75
#define PIPE_MAX_HEIGHT     75 + PIPE_GAPE_V
#define PIPE_WIDTH          66
#define PIPE_SEPARATION_H   250
#define PIPE_GAPE_V         150
#define PIPE_SPEED          1.5
#define PIPE_COLOR          DARKGRAY
#define PIPE_LIST_SIZE      16

//GROUND + CEILING OPTIONS --
#define GROUND_HEIGHT       SCREEN_HEIGHT - 33
#define CEILING_HEIGHT      33
#define CEILING_GROUND_COL  DARKGRAY

#endif