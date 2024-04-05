#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // for strcpy and strcmp
#define NUM_COLORS 6

int main() {
    char sequence[5]; // Assuming we want a sequence of 4 letters + null terminator

    // Generate a random sequence of 4 letters with each letter used only once
    printf("Bienvenu au jeu MASTERMIND!!!\n");
    char mode;
    do {
        printf("Souhaitez-vous jouer en mode HARD ou EASY ? \n");
        scanf(" %c", &mode); // Add a space before %c to consume leading whitespace characters

        // Clear the input buffer
        while (getchar() != '\n'); // Consume characters until newline is encountered

        if (mode == 'H' || mode == 'h') {
            printf("Vous avez choisi le mode HARD \n");
            generateRandomSequence_HARD(sequence, 4);
        } else if (mode == 'E' || mode == 'e') {
            printf("Vous avez choisi le mode EASY \n");
            generateRandomSequence_EASY(sequence, 4);
        } else {
            printf("Vous n'avez pas choisi un mode valide \n");
        } 
    } while (mode != 'H' && mode != 'h' && mode != 'E' && mode != 'e');

    printf("    ▁▁▁▁▁▁▁▁▁▁▁▁\n");
    printf("    ┃GAME START┃\n");
    printf("    ▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("Random sequence: %s\n", sequence);
    evaluation(sequence);
    return 0;
}