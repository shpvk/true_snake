#include "includes.h"
#include "constants.h"
#include "direction.h"

void update_direction(int& dx, int& dy, int last_dx, int last_dy)
{
    if (GetAsyncKeyState(VK_UP) && !(last_dx == 0 && last_dy == 1)) {
        dx = 0; dy = -1;
    }
    else if (GetAsyncKeyState(VK_DOWN) && !(last_dx == 0 && last_dy == -1)) {
        dx = 0; dy = 1;
    }
    else if (GetAsyncKeyState(VK_LEFT) && !(last_dx == 1 && last_dy == 0)) {
        dx = -1; dy = 0;
    }
    else if (GetAsyncKeyState(VK_RIGHT) && !(last_dx == -1 && last_dy == 0)) {
        dx = 1; dy = 0;
    }
}