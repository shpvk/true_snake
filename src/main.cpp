#include "includes.h"
#include "constants.h"
#include "board.h"
#include "direction.h"
#include "snake.h"
#include "cursor.h"
#include "spawn_food.h"
int main()
{
    srand(time(0));
    char choice;
    do
    {
        char board[ROWS][COLS];
        snake body[100];
        int snake_length = 3;
        int direction_x = 1;
        int direction_y = 0;
        int last_dx = 1, last_dy = 0;
        bool is_dead = false;

        int food_x, food_y;
        spawn_food(food_x, food_y, body, snake_length);

        hide_cursor();
        initialize_board(board);
        initialize_snake(body, snake_length);

        while (!is_dead)
        {
            update_direction(direction_x, direction_y, last_dx, last_dy);

            for (int i = snake_length - 1; i > 0; --i)
            {
                body[i] = body[i - 1];
            }

            body[0].x += direction_x;
            body[0].y += direction_y;

            if (is_bump_with_wall(body, is_dead) || is_bump_with_self(body, snake_length))
            {
                is_dead = true;
                break;
            }
            if (body[0].x == food_x && body[0].y == food_y)
            {
                if (snake_length < 100) 
                {
                  ++snake_length;
                  spawn_food(food_x, food_y, body, snake_length);
                } else {
                        std::cout << "You win! Maximum length reached.\n";
                        break;
                    }
                }

            initialize_board(board);
            draw_snake_on_board(body, snake_length, board, is_dead);
            board[food_y][food_x] = '@';

            reset_cursor();
            print_board(board);

            last_dx = direction_x;
            last_dy = direction_y;

            Sleep(100);
        }

        std::cout << "YOU LOST\n";
        std::cout << "Do you want to play again? (N to exit, anything else to retry): ";
        std::cin >> choice;
        system("cls");
        choice = toupper(choice);

    } while (choice != 'N');
    return 0;
}
