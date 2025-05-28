#include "spawn_food.h"
#include  "includes.h"

void spawn_food(int& food_x, int& food_y, snake body[], int length) {
    bool on_snake;
    do {
        on_snake = false;
        food_x = rand() % (COLS - 2) + 1;
        food_y = rand() % (ROWS - 2) + 1;

        for (int i = 0; i < length; ++i) {
            if (body[i].x == food_x && body[i].y == food_y) {
                on_snake = true;
                break;
            }
        }
    } while (on_snake);
}
