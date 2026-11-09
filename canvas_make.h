#ifndef CANVASMAKE_H
#define CANVASMAKE_H

char **create_canvas(int width, int height);

void print_canvas(char **canvas, int width, int height);

void free_canvas(char **canvas, int height);

#endif