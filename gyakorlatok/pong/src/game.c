#include "game.h"

void resize_game(Game* game, int width, int height)
{
    game->width = width;
    game->height = height;
    game->left_pad.size = 200;
    game->right_pad.size = 200;
    restart_game(game);
}

void restart_game(Game* game)
{
    float center_x;
    float center_y;

    center_x = game->width / 2;
    center_y = game->height / 2;

    move_pad(&(game->left_pad), center_y, game->height);
    move_pad(&(game->right_pad), center_y, game->height);
    game->left_pad.colorR = 0.8;
    game->right_pad.colorR = 0.2;
    start_ball(&(game->ball), center_x, center_y);
}

void update_game(Game* game, double time)
{
    update_ball(&(game->ball), time);
    if (game->ball.x - game->ball.radius < 50 && game->ball.y >=game->left_pad.position && game->ball.y <=(game->left_pad.position + game -> left_pad.size))  {
        game->ball.x = game->ball.radius + 50;
        game->ball.speed_x *= -1;
        game->ball.colorB = 0.0;
        game->left_pad.colorR = 1 - game->left_pad.colorR;
        // bal oldalról pattan
    }
    if (game->ball.x + game->ball.radius > game->width - 50) {
        game->ball.x = game->width - game->ball.radius - 50;
        game->ball.speed_x *= -1;
         game->ball.colorB = 1.0;
         game->right_pad.colorR = 1 - game->right_pad.colorR;
         //jobb oldalról pattan
    }
    if (game->ball.y - game->ball.radius < 0) {
        game->ball.y = game->ball.radius;
        game->ball.speed_y *= -1;
         game->ball.colorR = 1.0;
         //oldal teteje
    }
    if (game->ball.y + game->ball.radius > game->height) {
        game->ball.y = game->height - game->ball.radius;
        game->ball.speed_y *= -1;
        game->ball.colorR = 0.0;
        //oldal alja
    }
}

void move_left_pad(Game* game, float position)
{
    move_pad(&(game->left_pad), position, game->height);
}

void move_right_pad(Game* game, float position)
{
    move_pad(&(game->right_pad), position, game->height);
}

