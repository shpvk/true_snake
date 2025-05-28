#include "includes.h"
#include "board.h"

void initialize_board(char board[ROWS][COLS]) {
  for (int y = 0; y < ROWS; ++y) {
    for (int x = 0; x < COLS; ++x) {
      if (y == 0 || y == ROWS - 1 || x == 0 || x == COLS - 1)
        board[y][x] = '|';
      else
        board[y][x] = ' ';
    }
  }
}

void draw_snake_on_board(snake body[], int length, char board[ROWS][COLS], bool &is_dead) {
  for (int i = 0; i < length; ++i) {
    if (body[i].y >= 0 && body[i].y < ROWS &&
        body[i].x >= 0 && body[i].x < COLS) {
      board[body[i].y][body[i].x] = (i == 0 ? '0' : 'o');
    }
  }
}

void print_board(char board[ROWS][COLS])
{
  const int BUFFER_SIZE = (COLS + 1) * ROWS + 1;
  char buffer[BUFFER_SIZE];
  int index = 0;

  for (int y = 0; y < ROWS; ++y)
  {
    for (int x = 0; x < COLS; ++x)
    {
      buffer[index++] = board[y][x];
    }
    buffer[index++] = '\n';
  }

  buffer[index] = '\0';
  std::cout << buffer;
}
