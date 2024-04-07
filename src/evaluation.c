/**
 * \file user_input4.c
 * \brief Compare les codes couleurs générées par la machine et entrée par l'utilisateur puis affiche les résultats.
 * code ---
 * \author AYVACI Yagiz
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // for strcpy and strcmp
#include "evaluation.h"
#define NUM_COLORS 6

int check_black_pins(char *user_code, char *machine_code, int length) {
    int black_pins = 0;
    for (int i = 0; i < length; i++) {
        if (user_code[i] == machine_code[i]) {
            black_pins++;
            user_code[i] = '*'; // Mark as checked
            machine_code[i] = '*';
        }
    }
    return black_pins;
}

int check_white_pins(char *user_code, char *machine_code, int length) {
    int white_pins = 0;
    for (int i = 0; i < length; i++) {
        if (user_code[i] != '*') {
            for (int j = 0; j < length; j++) {
                if (user_code[i] == machine_code[j]) {
                    white_pins++;
                    machine_code[j] = '*'; // Mark as checked
                    break;
                }
            }
        }
    }
    return white_pins;
}

void evaluation(char *machine_code) {
    const int tries = 4;
    char user_code[30], machine_code_copy[5], user_code_copy[5];
    int tries_left = tries;

    for (int i = 0; i < tries; i++) {
        strcpy(machine_code_copy, machine_code);
        user_input(user_code);
        strcpy(user_code_copy, user_code);

        int black_pins = check_black_pins(user_code_copy, machine_code_copy, 4);
        int white_pins = check_white_pins(user_code_copy, machine_code_copy, 4);

        printf("Number of black pins: %d\n", black_pins);
        printf("Number of white pins: %d\n", white_pins);

        if (black_pins == 4) {
            printf("    ▁▁▁▁▁▁▁▁▁\n");
            printf("    ┃YOU WIN┃\n");
            printf("    ▔▔▔▔▔▔▔▔▔\n");
            printf("Congratulations! You've cracked the code!\n");
            return;
        }

        tries_left--;
        if (tries_left > 0) {
            printf("Number of tries remaining: %d\n\n", tries_left);
        }
    }

    printf("    ▁▁▁▁▁▁▁▁▁▁▁\n");
    printf("    ┃GAME OVER┃\n");
    printf("    ▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("You've run out of tries.\n");
}
