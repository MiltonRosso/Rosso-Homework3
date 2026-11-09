#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <errno.h>
#include "canvas_make.h"

int main(int argc, char *argv[]) {
    
    // Checks to make sure the use gave 3 arguments.
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <height> <width>\n", argv[0]);
        return 0;
    }

    char *end_height;
    char *end_width;

    // Converts string into an integer.
    errno = 0;
    int h = strtol(argv[1], &end_height, 10);

    if((errno != 0) || (*end_height != '\0') || (h <= 0) || (h > INT_MAX)) {
        fprintf(stderr, "Error: height must be a positive integer.\n");
        return 0;
    }

    // Converts string to an integer.
    errno = 0;
    int w = strtol(argv[2], &end_width, 10);

    if(errno != 0 || *end_width != '\0' || w <= 0 || w > INT_MAX) {
        fprintf(stderr, "Error: width must be a positive integer.\n");
        return 0;
    }

    int height = (int) h;
    int width = (int) w;

    srand((unsigned int) time(NULL));

    char **canvas = create_canvas(width, height);

    if(canvas == NULL) {
        fprintf(stderr, "Error: could not allocate canvas memory.\n");
        return 0;
    }

    print_canvas(canvas, width, height);
    free_canvas(canvas, height);

    return 0;
}