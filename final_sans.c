#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // for strcpy and strcmp
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

void user_input(char *input) {
    int valid_input = 0;

    while (valid_input == 0) {
        printf("Veuillez entrer votre combinaison de 4 lettres (R,C,Y,G,B,P): \n");
        scanf("%s", input); // Read user input

        if (verifier(input)) {
            valid_input = 1; // Mark input as valid
        }
    }
}

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

// Function to start the game
int gamebeggining() {
    char sequence[5]; // Assuming we want a sequence of 4 letters + null terminator

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random sequence of 4 letters
    printf("Bienvenu au jeu MASTERMIND!!!\n");
    char mode[5];
    do {
        printf("Souhaitez-vous jouer en mode HARD ou EASY ? \n");
        scanf(" %s", mode);

        // Clear the input buffer
        while (getchar() != '\n'); // Consume characters until newline is encountered

        if (strcasecmp(mode, "HARD") == 0) {
            printf("Vous avez choisi le mode HARD \n");
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

void repeat() {
    char answer[30];
    do {
        printf("\n");
        printf("Souhaitez-vous rejouer ? (Oui/Non): ");
        scanf("%s", answer);
        if ((strcmp(answer, "Oui") == 0) || (strcmp(answer, "oui") == 0)) {
            printf("Le jeu recommence!\n\n");
            gamebeggining();
        } else if ((strcmp(answer, "Non") == 0) || (strcmp(answer, "non") == 0)) {
            printf("Merci d'avoir joué!\n");
        } else {
            printf("Veuillez répondre par Oui ou par Non.\n\n");
        }
    } while ((strcmp(answer, "Non") != 0) && (strcmp(answer, "non") != 0));
}

int main() {
    char sequence[5]; // Assuming we want a sequence of 4 letters + null terminator
    gamebeggining();
    repeat();
    return 0;
}
