#include "includes.h"
#include "board.h"


void initialize_board(char board[COLS][ROWS]) {
  for (int i = 0; i < COLS; ++i) {
    for (int j = 0; j < ROWS; ++j) {
      if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
        board[i][j] = '|';
      else
        board[i][j] = ' ';
    }
  }
}

void draw_snake_on_board(snake body[], int length, char board[COLS][ROWS], bool &is_dead) {
  for (int i = 0; i < length; ++i) {
    if (i == 0)
      board[body[i].y][body[i].x] = '0';
    else
      board[body[i].y][body[i].x] = 'o';
  }
}

void print_board(char board[COLS][ROWS])
{
  const int BUFFER_SIZE = (COLS + 1) * ROWS + 1;
  char buffer[BUFFER_SIZE];
  int index = 0;

  for (int i = 0; i < ROWS; ++i)
  {
    for (int j = 0; j < COLS; ++j)
    {
      buffer[index++] = board[i][j];
    }
    buffer[index++] = '\n';
  }

  buffer[index] = '\0';

  std::cout << buffer;
}