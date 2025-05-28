#pragma once
#include "constants.h"

void initialize_board(char board[COLS][ROWS]);
void draw_snake_on_board(snake body[], int length, char board[COLS][ROWS], bool &is_dead);
void print_board(char board[COLS][ROWS]);
