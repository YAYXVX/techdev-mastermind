#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // for strcpy and strcmp
#include "evaluation.h"
#include "random.h"
#include "repeat.h"
#include "game_beggining.h"
#include "user_input.h"
#define NUM_COLORS 6

// Main function
int main() {
    gamebeggining();
    repeat();
    return 0;
}
