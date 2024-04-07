/**
 * @file repeat.h
 * @brief Defines the function for prompting the player to play again.
 *
 * @details Declares the `repeat` function, which interacts with the player
 * asking if they wish to replay the game, handling their response accordingly.
 *
 * @author Martin
 *
 * @defgroup replay Prompt Replay
 * @{
 * Function for inquiring the player about replaying the game, ensuring
 * continuous play or proper game termination based on player input.
 */

#ifndef REPEAT_H
#define REPEAT_H

/**
 * @brief Prompts the player whether they want to play again.
 *
 * @details After a game session ends, asks the player if they wish to
 * start a new game or exit. Accepts affirmative and negative responses,
 * restarting the game or exiting based on the player's input.
 */
void repeat();

/** @} */ // End of replay group
#endif // REPEAT_H

