/**
 * \file user_input4.c
 * \brief Demande à l'utilisateur débute le jeu MASTERMIND et demande à l'utilisateur si il veut jouer en difficulté Hard ou Easy.
 * code ---
 * \author AYVACI Yagiz
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // for strcpy and strcmp
#include "game_beggining.h"
#define NUM_COLORS 6

// Function to start the game
int gamebeggining() {
    char sequence[5]; // Assuming we want a sequence of 4 letters + null terminator

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random sequence of 4 letters
    printf("Bienvenu au jeu MASTERMIND!!!\n");
    char mode[10];
    do {
        printf("Souhaitez-vous jouer en mode HARD ou EASY ? \n");
        scanf(" %s", mode);

        // Clear the input buffer
        while (getchar() != '\n'); // Consume characters until newline is encountered

        if (strcasecmp(mode, "HARD") == 0) {
            printf("Vous avez choisi le mode HARD \n");
            sequence[4] = '\0';
            generateRandomSequence_HARD(sequence, 4);
        } else if (strcasecmp(mode, "EASY") == 0) {
            printf("Vous avez choisi le mode EASY \n");
            generateRandomSequence_EASY(sequence, 4);
        } else {
            printf("Vous n'avez pas choisi un mode valide \n");
        }
    } while ((strcasecmp(mode, "HARD") != 0) && (strcasecmp(mode, "EASY") != 0));

    printf("    ▁▁▁▁▁▁▁▁▁▁▁▁\n");
    printf("    ┃GAME START┃\n");
    printf("    ▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("Random sequence: %s\n", sequence);
    evaluation(sequence);
    return 0;
}
