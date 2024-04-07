/**
 * @file user_input.h
 * @brief Defines functions for user input validation and interaction.
 *
 * @details This file declares functions that facilitate user interaction
 * by prompting for input and validating it against specific criteria. These functions
 * ensure that the user inputs a valid sequence of characters for the game.
 *
 * @author Martin
 *
 * @defgroup user_input User Input Handling
 * @{
 * Functions dedicated to obtaining and validating user input, ensuring compliance
 * with the game's requirements for character sequences.
 */

#ifndef USER_INPUT_H
#define USER_INPUT_H

/**
 * @brief Validates the user's input.
 *
 * @details Checks if the provided input meets the game's requirements for length
 * and character composition. Prompts the user for a re-entry if the input is invalid.
 *
 * @param input A string containing the user's input.
 * @return 1 if the input is valid, 0 otherwise.
 */
int verifier(char *input);

/**
 * @brief Obtains and validates a sequence of characters from the user.
 *
 * @details Prompts the user to enter a combination of 4 letters, repeatedly asking
 * until a valid input is provided. Utilizes `verifier` to validate input.
 *
 * @param input A string to store the user's input.
 */
void user_input(char *input);

/** @} */ // End of user_input group
#endif // USER_INPUT_H
