/**
 * \file user_input4.c
 * \brief Demande à l'utilisateur d'entrer une chaine de 4 caractères, et ensuite evalue la chaine entrée
 * code ---
 * \author AYVACI Yagiz
 */
 
#include <stdio.h>

int main(){
  printf("Bienvenu au jeu MASTERMIND!!! \nSouhaitez-vous jouer en mode HARD ou EASY ? \n");
  char mode;
  scanf("%c", &mode);
  if (mode == 'H'){ 
    printf("Vous avez choisi le mode HARD. \n");
  } else {
    printf("Vous avez choisi le mode EASY. \n");
  }
}
