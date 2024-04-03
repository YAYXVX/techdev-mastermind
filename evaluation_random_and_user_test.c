#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // for strcpy and strcmp


#define NUM_COLORS 6

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
void generateRandomSequence(char *sequence, int length) {
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

int verifier(char *input) {
  int input_length = 0;

  // Calculer la longueur de l'entrée
  while (input[input_length] != '\0') {
    input_length++;
  }

  // Vérifier si la longueur est différente de 4
  if (input_length != 4) {
    // Si la longueur est inférieure à 4
    if (input_length < 4) {
      printf("Veuillez entrer exactement 4 lettres.\n");
    }
    // Si la longueur est supérieure à 4
    else {
      printf("Veuillez entrer seulement 4 lettres.\n");
    }
    return 0; // L'entrée n'est pas valide
  }

  // Vérifier la compatibilité des lettres
  for (int i = 0; i < 4; i++) {
    if (input[i] != 'R' && input[i] != 'C' && input[i] != 'Y' &&
        input[i] != 'G' && input[i] != 'B' && input[i] != 'P') {
      printf("Les lettres doivent correspondre strictement à (R, C, Y, G, B, P).\n");
      return 0; // L'entrée n'est pas valide
    }
  }
  return 1; // L'entrée est valide
}


void user_input(char *input) {
  int valid_input = 0;

  while (valid_input == 0) {
    printf("Veuillez entrer votre combinaison de 4 lettres (R,C,Y,G,B,P): \n");
    scanf("%s", input); // Lire l'entrée utilisateur

    if (verifier(input)) {
      valid_input = 1; // Marquer l'entrée comme valide
    }
  }
}

// Function to evaluate the user's input and the machine's output to determine the number of correct colors and positions
void evaluation(char *machine_code) {
    int tries = 4;       // Number of tries allowed
    int tries_tmp = tries; 
    char user_code[5];    // Buffer to store user's code

    // Loop for 4 tries
    for (int i = 0; i < tries; i++) {
        int black_pins = 0;
        int white_pins = 0;
        char machine_code_copy[5];
        char user_code_copy[5];

        // Copy the machine and user codes to temporary arrays
        strcpy(machine_code_copy, machine_code);
        user_input(user_code);
        strcpy(user_code_copy, user_code);

        // Check for black pins (correct color and position)
        for (int j = 0; j < 4; j++) {
            if (user_code_copy[j] == machine_code_copy[j]) {
                black_pins++;
                // Mark positions to ignore for white pins
                user_code_copy[j] = '*';
                machine_code_copy[j] = '*';
            }
        }

        // Check for white pins (correct color but wrong position)
        for (int j = 0; j < 4; j++) {
            if (user_code_copy[j] != '*') {
                for (int k = 0; k < 4; k++) {
                    if (machine_code_copy[k] != '*' && user_code_copy[j] == machine_code_copy[k]) {
                        white_pins++;
                        // Mark positions to ignore for subsequent white pins
                        user_code_copy[j] = '*';
                        machine_code_copy[k] = '*';
                        break;
                    }
                }
            }
        }

        // If all colors are correct, exit the loop
        printf("Number of black pins: %d\n", black_pins);
        printf("Number of white pins: %d\n", white_pins);
        if (black_pins == 4) {
            printf("    ▁▁▁▁▁▁▁▁▁\n");
            printf("    ┃YOU WIN┃\n");
            printf("    ▔▔▔▔▔▔▔▔▔\n");
            printf("Congratulations! You've cracked the code!\n");
            return;
        }

        // Print remaining tries
        tries_tmp--;
        if (tries_tmp != 0) {
            printf("Nombre d'essaies restants: %d\n", tries_tmp);
            printf("\n");
        }
    }

    // If the loop completes without breaking, it means the user has run out of tries
    printf("    ▁▁▁▁▁▁▁▁▁▁▁\n");
    printf("    ┃GAME OVER┃\n");
    printf("    ▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("You've run out of tries.\n");
}

int main() {
    char sequence[5]; // Assuming we want a sequence of 4 letters + null terminator

    // Generate a random sequence of 4 letters with each letter used only once
    printf("    ▁▁▁▁▁▁▁▁▁▁▁▁\n");
    printf("    ┃GAME START┃\n");
    printf("    ▔▔▔▔▔▔▔▔▔▔▔▔\n");
    generateRandomSequence(sequence, 4);
    printf("Random sequence: %s\n", sequence);
    evaluation(sequence);
    return 0;
}
