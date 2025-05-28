#include "includes.h"
#include "constants.h"
#include "direction.h"



void update_direction(int& direction_x, int& direction_y)
{
  if (GetAsyncKeyState(VK_UP)) { direction_x = 0; direction_y = -1; }
  else if (GetAsyncKeyState(VK_DOWN)) { direction_x = 0; direction_y = 1; }
  else if (GetAsyncKeyState(VK_LEFT)) { direction_x = -1; direction_y = 0; }
  else if (GetAsyncKeyState(VK_RIGHT)) { direction_x = 1; direction_y = 0; }
}
