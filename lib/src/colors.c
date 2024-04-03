/**
 * @file colors.c
 * @brief Implementation of print_color function
 *
 * @author Martin
 * 
 * @ingroup color
 */

#include <stdio.h>
#include "colors.h"

void print_color(const char *text, const char color) {
    switch (color) {
        case 'R':
            printf("\033[31m%s\033[0m", text); // Red
            break;
        case 'G':
            printf("\033[32m%s\033[0m", text); // Green
            break;
        case 'Y':
            printf("\033[33m%s\033[0m", text); // Yellow
            break;
        case 'B':
            printf("\033[34m%s\033[0m", text); // Blue
            break;
        case 'P':
            printf("\033[35m%s\033[0m", text); // Purple
            break;
        case 'C':
            printf("\033[36m%s\033[0m", text); // Cyan
            break;
        default:
            printf("%s", text); // Default color
    }
}

