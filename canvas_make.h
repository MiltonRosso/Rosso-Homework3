#ifndef CANVASMAKE_H
#define CANVASMAKE_H

char **createCanvas(int width, int height);

void printCanvas(char **canvas, int width, int height);

void freeCanvas(char **canvas, int width, int height);

#endif