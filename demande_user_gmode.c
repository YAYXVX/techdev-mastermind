/**
 * \file user_input4.c
 * \brief Demande à l'utilisateur d'entrer une chaine de 4 caractères, et ensuite evalue la chaine entrée
 * code ---
 * \author AYVACI Yagiz
 */
 
#include <stdio.h>

int main() {
    printf("Bienvenu au jeu MASTERMIND!!!\n");
    char mode;
    do {
        printf("Souhaitez-vous jouer en mode HARD ou EASY ? \n");
        scanf(" %c", &mode); // Add a space before %c to consume leading whitespace characters

        if (mode == 'H' || mode == 'h') {
            printf("Vous avez choisi le mode HARD \n");
        } else if (mode == 'E' || mode == 'e') {
            printf("Vous avez choisi le mode EASY \n");
        } else {
            printf("Vous n'avez pas choisi un mode valide \n");
        } 
    } while (mode != 'H' && mode != 'h' && mode != 'E' && mode != 'e');
    
    return 0;
}

