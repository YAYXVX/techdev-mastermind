/**
 * @file game_beggining.h
 * @brief Prompts the user to start the MASTERMIND game and asks whether they want to play in Hard, Easy mode or file mode.
 *
 * @details This header file contains declarations of functions used for initializing the game,
 * choosing the game difficulty, generating random sequences based on the selected difficulty,
 * and evaluating the player's guesses.
 *
 * @author Martin
 */

#ifndef GAME_BEGGINING_H
#define GAME_BEGGINING_H

#define NUM_COLORS 6

/**
 * @brief Starts the game by welcoming the player, and prompts them to choose between Hard and Easy mode.
 *
 * @details This function seeds the random number generator, prompts the user to select a game mode,
 * generates a random sequence based on the chosen difficulty, and starts the game evaluation.
 *
 * @return int Returns 0 to indicate the game was initialized successfully.
 */
int gamebeggining(void);

#endif // GAME_BEGGINING_H
