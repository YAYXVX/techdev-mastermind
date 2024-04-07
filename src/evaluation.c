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
#include "user_input.h"
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
    const int tries = 10;
    char user_code[30], machine_code_copy[5], user_code_copy[5];
    int tries_left = tries;

  printf("Veuillez entrer votre combinaison de 4 lettres (R,C,Y,G,B,P): \n");

  printf("\n| guess # | guess | result             | tries left |\n");
  printf("| ------- | ----- | ------------------ | ---------- | Votre code: ");
  
    for (int i = 0; i < tries; i++) {
        strcpy(machine_code_copy, machine_code);
        user_input(user_code);
        strcpy(user_code_copy, user_code);

        int black_pins = check_black_pins(user_code_copy, machine_code_copy, 4);
        int white_pins = check_white_pins(user_code_copy, machine_code_copy, 4);
        tries_left--;

      printf("| %-7d | %-5s | black: %d, white: %d | %-10d | Votre code: ", i+1, user_code, black_pins, white_pins, tries_left);

      if (black_pins == 4) {
          printf("\n");
          printf("    ▁▁▁▁▁▁▁▁▁\n");
          printf("    ┃YOU WIN┃\n");
          printf("    ▔▔▔▔▔▔▔▔▔\n");
          printf("Toutes nos félicitations! Vous avez déchiffré le code !\n");
          return;
      }
    }

  printf("\n");
  printf("    ▁▁▁▁▁▁▁▁▁▁▁\n");
  printf("    ┃GAME OVER┃\n");
  printf("    ▔▔▔▔▔▔▔▔▔▔▔\n");
  printf("    WOMP WOMP!!\n");
  printf("Vous n'avez plus d'essais :[\n");
  }
