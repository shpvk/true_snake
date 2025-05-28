#include "constants.h"
#include "snake.h"

void initialize_snake(snake body[], int length)
{
  int start_x = COLS / 2;
  int start_y = ROWS / 2;

  for (int i = 0; i < length; ++i)
  {
    body[i].x = start_x - i;
    body[i].y = start_y;
  }
}

bool is_bump_with_wall(snake body[], bool &is_dead)
{

  if (body[0].x <= 0 || body[0].x >= COLS - 1 ||
    body[0].y <= 0 || body[0].y >= ROWS - 1)
  {
    is_dead = true;
    return is_dead;
  }
  return is_dead;
}