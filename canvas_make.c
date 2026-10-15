#include <stdio.h>
#include <stdlib.h>
#include "canvasMake.h"

static const char char_list[] = {'?', '#', '@', '$', '%', '&', '*', '/'};

/*
 * Parameters: char_list is the character list; size_of is its length.
 * Returns: A randomly selected character.
 * Purpose: Selects a random character from the supplied list.
 */
static char pick_char(const char char_list[], int size_of)
{
    return char_list[rand() % size_of];
}

/*
 * Parameters: chance is the probability of returning a character;
 *             char_list is the available character list;
 *             size_of is the number of characters in the list.
 * Returns: A random character or a space.
 * Purpose: Returns a character with the specified probability,
 *          and a space otherwise.
 */
static char gen_rand_char(double chance,
                          const char char_list[],
                          int size_of)
{
    double random_number =
        (double) rand() / ((double) RAND_MAX + 1.0);

    if (random_number < chance)
    {
        return pick_char(char_list, size_of);
    }

    return ' ';
}

char **create_canvas(int width, int height)
{
    int char_count = sizeof(charList) / sizeof(charList[0]);

    char **canvas = malloc(sizeof(*canvas) * height);

    if (canvas == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < height; i++)
    {
        canvas[i] = malloc(sizeof(*canvas[i]) * width);

        if (canvas[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(canvas[j]);
            }

            free(canvas);
            return NULL;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            canvas[i][j] =
                gen_rand_char(0.20, charList, char_count);
        }
    }

    return canvas;
}

void print_char(char **canvas, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", canvas[i][j]);
        }

        printf("\n");
    }
}

void free_canvas(char **canvas, int width, int height)
{
    (void) width;

    if (canvas == NULL)
    {
        return;
    }

    for (int i = 0; i < height; i++)
    {
        free(canvas[i]);
    }

    free(canvas);
}