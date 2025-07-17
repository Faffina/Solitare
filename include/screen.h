#ifndef SCREEN_H
#define SCREEN_H
#include <stdint.h>
#include <stdlib.h>
#include <termios.h>

extern struct termios old_terminal, new_terminal;

typedef struct {
    int r, g, b;
} color;

typedef struct {
    char c[5];
    color text, backgournd;
} screen_pixel;

typedef struct {
    size_t h, w;
    screen_pixel* data;
} texture;

extern texture* main_screen;

void init();
void end();
texture* create_texture(int h, int w);
void free_texture(texture* t);
void drow_pixel(texture* t, int y, int x, screen_pixel p);
void refresh();

#endif
