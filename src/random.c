/**
 * \file user_input4.c
 * \brief Demande à l'utilisateur d'entrer une chaine de 4 caractères, et ensuite evalue la chaine entrée
 * code ----
 * \author AYVACI Yagiz
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // for strcpy and strcmp
#include "random.h"
#define NUM_COLORS 6

// Function to generate a random sequence of letters
void generateRandomSequence_HARD(char *sequence, int length) {
    // Array containing the available letters
    char colors[NUM_COLORS] = {'R', 'C', 'Y', 'G', 'B', 'P'};
    for (int i = 0; i < length; i++) {
        int index = rand() % NUM_COLORS;
        sequence[i] = colors[index];
    }
}

// Function to shuffle an array
void shuffleArray(char *array, int length) {
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to generate a random sequence of letters
void generateRandomSequence_EASY(char *sequence, int length) {
    // Array containing the available letters
    char colors[NUM_COLORS] = {'R', 'C', 'Y', 'G', 'B', 'P'};

    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the array of colors
    shuffleArray(colors, NUM_COLORS);

    // Generate random sequence
    for (int i = 0; i < length; i++) {
        sequence[i] = colors[i];
    }
    sequence[length] = '\0'; // Null-terminate the string
}
