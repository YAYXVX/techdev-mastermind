#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Function to evaluate the user's input and the machine's output to determine the number of correct colors
int evaluation(char *machine_code) {
    int tries = 4;       // Number of tries allowed
    int tries_tmp = tries; 
    char user_code[5];    // Buffer to store user's code

    // Loop for 10 tries
    for (int i = 0; i < tries; i++) {
      printf("Nombre d'essaies restants: %d\n", tries);
      tries_tmp = tries_tmp - 1;
        // Get user input for the color code
        user_input(user_code);

        int num_correct_colors = 0;

        // Check each color in the user's code
        for (int j = 0; j < 4; j++) {
            // Compare the color with each color in the machine's code
            for (int k = 0; k < 4; k++) {
                if (user_code[j] == machine_code[k]) {
                    num_correct_colors++;
                    break; // Move to the next color in the user's code
                }
            }
        }
        printf("Nombre d'essaies restants: %d\n", tries_tmp);
        printf("Number of correct colors: %d\n", num_correct_colors);

        // If all colors are correct, exit the loop
        if (num_correct_colors == 4) {
            printf("Congratulations! You've cracked the code!\n");
            return 1;
        }
    }
    printf("Game over! You've run out of tries.\n");
    return 0;
}

int main() {
    char sequence[5]; // Assuming we want a sequence of 4 letters + null terminator
    char input[5]; // Tampon pour stocker 4 caractères + le caractère nul
    // Generate a random sequence of 4 letters with each letter used only once
    generateRandomSequence(sequence, 4);
    printf("Random sequence: %s\n", sequence);
    // printf("Random sequence generated: ****\n");
    evaluation(sequence);
    return 0;
}
