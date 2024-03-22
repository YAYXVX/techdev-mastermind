/**
 * \file user_input4.c
 * \brief Demande à l'utilisateur d'entrer une chaine de 4 caractères, et ensuite evalue la chaine entrée
 * code ---
 * \author AYVACI Yagiz
 */

#include <stdio.h>

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
    printf("Veuillez entrer votre combinaison de 4 lettres (R,C,Y,G,B,P): \n");
    scanf("%s", input); // Lire l'entrée utilisateur

    if (verifier(input)) {
      valid_input = 1; // Marquer l'entrée comme valide
    }
  }
}

int main() {
  char input[5]; // Tampon pour stocker 4 caractères + le caractère nul
  user_input(input);
  printf("Votre combinaison de couleurs est: %s\n", input);
  return 0;
}
