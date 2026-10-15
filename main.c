#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <time.h>
#include "canvasMake.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <height> <width>\n", argv[0]);
        return 1;
    }

    char *end_height;
    char *end_width;

    errno = 0;
    long h = strtol(argv[1], &end_height, 10);

    if (errno != 0 || *end_height != '\0' || h <= 0 || h > INT_MAX)
    {
        fprintf(stderr, "Error: height must be a positive integer.\n");
        return 1;
    }

    errno = 0;
    long w = strtol(argv[2], &end_width, 10);

    if (errno != 0 || *end_width != '\0' || w <= 0 || w > INT_MAX)
    {
        fprintf(stderr, "Error: width must be a positive integer.\n");
        return 1;
    }

    int height = (int) h;
    int width = (int) w;

    srand((unsigned int) time(NULL));

    char **canvas = createCanvas(width, height);

    if (canvas == NULL)
    {
        fprintf(stderr, "Error: could not allocate canvas memory.\n");
        return 1;
    }

    printCanvas(canvas, width, height);
    freeCanvas(canvas, width, height);

    return 0;
}