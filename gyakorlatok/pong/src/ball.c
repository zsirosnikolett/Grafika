#include "ball.h"

void move_ball(Ball* ball, float x, float y)
{
    ball->x = x;
    ball->y = y;
}

void start_ball(Ball* ball, float x, float y)
{
    ball->colorB = 0.0;
    ball->colorG = 0.5;
    ball->colorR = 0.5;
    ball->radius = 20;
    move_ball(ball, x, y);
    ball->speed_x = 100;
    ball->speed_y = 100;
}

void update_ball(Ball* ball, double time)
{
    ball->x += ball->speed_x * time;
    ball->y += ball->speed_y * time;
}

