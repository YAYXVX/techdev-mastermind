/**
 * @file evaluation.h
 * @brief Defines the functions for evaluating the user's guesses against the machine code or file code in the game Mastermind.
 *
 * @details Declarations of the functions that control the evaluation logic
 * for the Mastermind game. These functions determine the correctness of the user's guesses
 * by comparing them with a secret code, providing feedback through black and white pins.
 *
 * @author Martin
 *
 * @defgroup evaluation Evaluation Logic
 * @{
 * This group includes functions that are crucial for evaluating the guesses made by the user, 
 * offering a systematic way to measure the accuracy of these guesses in relation to the secret code.
 */

#ifndef EVALUATION_H
#define EVALUATION_H

#include <stdio.h>

/**
 * @brief Calculates the number of black pins.
 *
 * @details This function compares the user's code with the machine's code
 * to determine the number of correct guesses in the right position (black pins).
 *
 * @param user_code A string representing the user's guess.
 * @param machine_code A string representing the machine's secret code.
 * @param length The length of the codes to be compared.
 * @return The number of black pins.
 */
int check_black_pins(char *user_code, char *machine_code, int length);

/**
 * @brief Calculates the number of white pins.
 *
 * @details This function compares the user's code with the machine's code
 * to determine the number of correct guesses in the wrong position (white pins).
 *
 * @param user_code A string representing the user's guess.
 * @param machine_code A string representing the machine's secret code.
 * @param length The length of the codes to be compared.
 * @return The number of white pins.
 */
int check_white_pins(char *user_code, char *machine_code, int length);

/**
 * @brief Manages the evaluation of the user's guesses.
 *
 * @details This is the main evaluation function that uses both
 * `check_black_pins` and `check_white_pins` to provide feedback to the user
 * after each guess, indicating how close they are to cracking the code.
 *
 * @param machine_code The machine's secret code that the user is trying to guess.
 */
void evaluation(char *machine_code);

/** @} */ // End of evaluation group
#endif // EVALUATION_H
