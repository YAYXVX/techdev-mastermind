/**
 * \file user_input4.c
 * \brief Demande à l'utilisateur s'il/elle souhaite répéter la partie ou s'il souhaite quitter
 * code ---
 * \author AYVACI Yagiz
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // for strcpy and strcmp
#include "repeat.h"
#define NUM_COLORS 6

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
