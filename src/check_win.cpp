#include "includes.h"
#include  "check_win.h"

bool check_win(int score, int target_score) {
    if (score >= target_score) {
        std::cout << "YOU WIN! You ate: " << score << " apples.\n";
        return true;
    }
    return false;
}