/**
 * \file user_input4.c
 * \brief Demande à l'utilisateur d'entrer une chaine de 4 caractères, et ensuite evalue la chaine entrée
 * code ---
 * \author AYVACI Yagiz, Martin
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // for strcpy and strcmp
#include "user_input.h"
#define NUM_COLORS 6
#include <errno.h>
//#include <unistd.h>

/*
 * @brief Function for reading the file
 */
void read_code_from_file(char *sequence) {
    // char cwd[1024]; // Store current directory path
    // if (getcwd(cwd, sizeof(cwd)) != NULL) { // If directory path is retrieved
    //     printf("Current working dir: %s\n", cwd); // Print current directory
    // } else {
    //     perror("getcwd() error"); // Print error if getcwd fails
    // }

    // Attempt to open file
    FILE *file = fopen("secret-sequence.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Try to read sequence from file
    if (fscanf(file, "%s", sequence) != 1) {
        printf("Error: Failed to read code from file.\n");
        fclose(file);
        exit(1);
    }

    fclose(file); // Close file
}


/**
 * fonction int verifier(char *input);
 * Crée un entier input_length = 0
 * Dans un while loop (tant que input[input_length] != '\0')
 *   incrémente la longeur de input_length de 1 pour calculer la longeur de input 
 * Retourne input_length Si input_length est plus petit que 4, il demande à l'utilisateur 
   de rentrer une chaine de caractère avec 4 caractères 
 * Si input_length est plus grand que 4, il demande à l'utilisateur de rentrer une
   chaine de caractère avec 4 caractères 
 * Si input_length est different de 4 il retourner 0 Si input_length est égale à 4 on entre       dans une boucle for
 * Si l'input[i] ne correspond pas à une lettre dans les 5 alors on retourne 0 
 * Si l'input[i] correspond à une lettre dans les 5 alors on retourne 1 ce qui veut dire que      l'input est valide
 */

int verifier(char *input) {
    int input_length = 0;

    // Calculate the length of the input
    while (input[input_length] != '\0') {
        input_length++;
    }

    // Check if the length is different from 4
    if (input_length != 4) {
        // If the length is less than 4
        if (input_length < 4) {
            printf("Veuillez entrer exactement 4 lettres.\n");
        }
        // If the length is greater than 4
        else {
            printf("Veuillez entrer seulement 4 lettres.\n");
        }
        return 0; // Input is not valid
    }

    // Check letter compatibility
    for (int i = 0; i < 4; i++) {
        if (input[i] != 'R' && input[i] != 'C' && input[i] != 'Y' &&
            input[i] != 'G' && input[i] != 'B' && input[i] != 'P') {
            printf("Les lettres doivent correspondre strictement à (R, C, Y, G, B, P).\n");
            return 0; // Input is not valid
        }
    }
    return 1; // Input is valid
}

/**
 * fonction void user_input(char *input);
 * Crée un entier valid_input = 0
 * Dans un while loop (tant que valid_input est 0)
 *   Demande à l'utilisateur d'entrer une combinaison de 4 lettres
 *   Appelle la fonction verifier
 *   Si la fonction verifier renvoie 1
 *     Affiche "Combinaison valide"
 * Si verifier(input) retourne 0, on recommence la boucle
 * Si verifier(input) retourne 1, on sort de la boucle et valid_input = 1
 */

void user_input(char *input) {
    int valid_input = 0;

    while (valid_input == 0) {
        scanf("%s", input); // Read user input

        if (verifier(input)) {
            valid_input = 1; // Mark input as valid
        }
    }
}
