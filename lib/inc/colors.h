/**
 * @file colors.h
 * @brief Declaration of print_color function.
 * @author Martin
 *
 * @defgroup color Color library
 * @{
 * This module is critical for the output clarity and readability of the program, giving an enhanced user experience.
 */
#ifndef COLORS_H
#define COLORS_H

/**
 * @brief Prints text in a specified color to the console.
 *
 * @details This function outputs the given text in a color specified by the \a color parameter.
 * It interprets the color codes as follows: 'R' for red, 'G' for green, 'Y' for yellow, 'B' for blue,
 * 'P' for purple, and 'C' for cyan. If an unsupported color code is provided, the text will be printed
 * in the default terminal color. The function uses ANSI escape codes to set the text color.
 *
 * @param text A pointer to the string of text to be printed. This parameter must not be NULL.
 * @param color A character representing the color code. The function expects uppercase letters for color codes.
 *
 * @note This function requires terminal support for ANSI escape sequences to correctly display colors.
 */
void print_color(const char *text, char color);

#endif // COLORS_H

