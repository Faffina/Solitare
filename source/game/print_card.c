#include "game.h" 
#include <ncurses.h>

void print_card(int y, int x, card c) {
    for(int i = 0; i < 5; i++)
        mvaddstr(y + i, x, card_sprite[c.s][c.v][i]);
}
