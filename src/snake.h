#pragma once
#include "constants.h"
#include "includes.h"
void initialize_snake(snake body[], int length);
bool is_bump_with_wall(snake body[], bool &is_dead);
bool is_bump_with_self(snake body[], int length);

