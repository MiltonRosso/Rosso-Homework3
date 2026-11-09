/*
 * Sources: Giraffe Academy
 * ChatGPT
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "canvas_make.h"

// List of supplied characters
static const char char_list[] = {'?', '#', '@', '$', '%', '&', '*', '/'};

// Randomly selects a character from the list of supplied characters.
static char pick_char(const char char_list[], int size_of) {
    return char_list[rand() % size_of];
}

/*
 * Returns a random character from the supplied list; there's and 80%
 * chance of selecting an empty space and 20% chance of selecting from
 * the supplied list of characters.
**/
static char gen_rand_char(const char char_list[], int size_of) {

    /*
     * Sets the input for our random number as the current time, and sets
     * the random number between 0 and 99.
    **/
    int random_number = rand() % 100;

    /*
     * Returns a character from the supplied list if the random number is
     * between 0 and 19.
    **/
    if(random_number < 20) {
        return pick_char(char_list, size_of);
    }
    
    // Returns a balnk spacxe if the random character is between 20 and 99.
    return ' ';
}

/*
 * Creates a 2D array, then fills it with random characters, returning a
 * pointer to to that array.
**/
char **create_canvas(int width, int height) {

    // Sets seed to curernt time.
    srand(time(NULL));

    // Stores the size of the list of supplied characters.
    int char_count = sizeof(char_list) / sizeof(char_list[0]);

    // Alocates memory for array the array of pointers.
    char **canvas = malloc(sizeof(*canvas) * height);

    // Checks to see if canvas points to anything.
    if(canvas == NULL) {
        return NULL;
    }

    // Alocates memory for width number of memory
    for(int i = 0; i < height; i++) {
        canvas[i] = malloc(sizeof(*canvas[i]) * width);

        // Checks to see if the ith canvas points to anything.
        if(canvas[i] == NULL) {
            for(int j = 0; j < i; j++) {
                free(canvas[j]);
            }
            free(canvas);
            return NULL;
        }
    }

    // Places a random character in each spot of alocated mamory.
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            canvas[i][j] = gen_rand_char(char_list, char_count);
        }
    }

    return canvas;
}

// Prints everything inside the 2D list.
void print_canvas(char **canvas, int width, int height) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%c", canvas[i][j]);
        }

        printf("\n");
    }
}

// Frees the memory
void free_canvas(char **canvas, int height) {
    if(canvas == NULL) {
        return;
    }

    for(int i = 0; i < height; i++) {
        free(canvas[i]);
    }

    free(canvas);
}