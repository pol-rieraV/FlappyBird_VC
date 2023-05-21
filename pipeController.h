#include "options.h"
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    
    Rectangle lower_pipe;
    Rectangle higher_pipe;
    float speed;

} pipeController;

void DrawPipePair(pipeController p) {
    DrawRectangleRec(p.lower_pipe, PIPE_COLOR);
    DrawRectangleRec(p.higher_pipe, PIPE_COLOR);
}

pipeController InitPipeController(int height_lower, int pipe_number){
    pipeController p;
    p.speed = PIPE_SPEED;

    // Higher Pipe
    p.higher_pipe.x = PIPE_SEPARATION_H * (pipe_number + 1);
    p.higher_pipe.y = CEILING_HEIGHT;
    p.higher_pipe.height = height_lower - CEILING_HEIGHT - PIPE_GAPE_V;
    p.higher_pipe.width = PIPE_WIDTH;

    // Lower Pipe
    p.lower_pipe.x = PIPE_SEPARATION_H * (pipe_number + 1);
    p.lower_pipe.y = height_lower;
    p.lower_pipe.height = SCREEN_HEIGHT - height_lower - CEILING_HEIGHT;
    p.lower_pipe.width = PIPE_WIDTH;

    return p;
}

void MovePipePair(pipeController* p) {
    p->higher_pipe.x -= p->speed;
    p->lower_pipe.x -= p->speed;
}

typedef struct {
    //I have the feeling that this is going to crash at some point. (it didn't)
    pipeController pipe_list[PIPE_LIST_SIZE];
} pipeList;

pipeList InitPipeList() {
    srand(0);
    pipeList p_list;
    int rand_num;
    for (int i = 0; i < PIPE_LIST_SIZE; i++) {
        rand_num = rand_num = 235 + rand() / (RAND_MAX / (325 - 235 +1) + 1);
        p_list.pipe_list[i] = InitPipeController(rand_num, i);
        //p_list.pipe_list[i] = InitPipeController(SCREEN_HEIGHT - 100, i);
        printf("%f\n", p_list.pipe_list[i].higher_pipe.height);
        printf("%f\n\n", p_list.pipe_list[i].lower_pipe.height);
    }
    return p_list;
}

void DrawPipeList(pipeList* p_list) {
    for (int i = 0; i < PIPE_LIST_SIZE; i++) {
        DrawPipePair(p_list->pipe_list[i]);
    }    
}

void MovePipeList(pipeList* p_list) {
    for (int i = 0; i < PIPE_LIST_SIZE; i++) {
        MovePipePair(&p_list->pipe_list[i]);
    }
}