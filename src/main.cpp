#include "includes.h"
#include "constants.h"
#include "board.h"
#include "direction.h"
#include "snake.h"
#include "cursor.h"

int main()
{
  char board[COLS][ROWS];
  snake body[100];
  int snake_length = 3;
  int direction_x = 1;
  int direction_y = 0;
  bool is_dead = false;

  hide_cursor();
  initialize_board(board);
  initialize_snake(body, snake_length);
  update_direction(direction_x, direction_y);
  draw_snake_on_board(body, snake_length, board, is_dead);
  print_board(board);

  while (!is_dead)
  {
    update_direction(direction_x, direction_y);

    // сдвигаю тело от хвоста к голове
    for (int i = snake_length - 1; i > 0; --i)
    {
      body[i] = body[i - 1];
    }

    // двигаю голову
    body[0].x += direction_x;
    body[0].y += direction_y;

    if (is_bump_with_wall(body, is_dead))
    {
      break;
    }

    initialize_board(board);
    draw_snake_on_board(body, snake_length, board, is_dead);

    
    reset_cursor();
    print_board(board);

    Sleep(100);
  }
  if (is_dead)
  {
    std::cout << "YOU LOST\n";
  }
  system("PAUSE");
  return 0;
}