/**
 * @file random.h
 * @brief Defines functions for generating random sequences and shuffling arrays.
 *
 * @details This file declares functions used in generating random sequences of characters
 * for the game and utility functions for shuffling arrays. These are used to create varied
 * and unpredictable game conditions.
 *
 * @author Martin
 *
 * @defgroup random Random Utilities
 * @{
 * Functions for generating random sequences and shuffling, providing the foundation
 * for game unpredictability and challenge.
 */

#ifndef RANDOM_H
#define RANDOM_H

/**
 * @brief Generates a random sequence of characters for the hard difficulty level.
 *
 * @details Populates a given array with a sequence of random characters
 * from a predefined set.
 *
 * @param sequence An array to hold the generated sequence.
 * @param length The desired length of the sequence.
 */
void generateRandomSequence_HARD(char *sequence, int length);

/**
 * @brief Shuffles the elements of an array.
 *
 * @details Randomly rearranges the elements of an array in place.
 *
 * @param array The array to be shuffled.
 * @param length The number of elements in the array.
 */
void shuffleArray(char *array, int length);

/**
 * @brief Generates a random sequence of characters for the easy difficulty level.
 *
 * @details Populates a given array with a sequence of characters
 * from a shuffled set, ensuring no repeats for the initial part of the sequence.
 *
 * @param sequence An array to hold the generated sequence.
 * @param length The desired length of the sequence.
 */
void generateRandomSequence_EASY(char *sequence, int length);

/** @} */ // End of random group
#endif // RANDOM_H
