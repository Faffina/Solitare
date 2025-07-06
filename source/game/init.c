#include "game.h" 
#include <ncurses.h>
#include <locale.h>

void init() {
    generate_card_sprite();
    setlocale(LC_ALL, "");
    initscr();              
    cbreak();               
    noecho();               
    keypad(stdscr, TRUE);   
    curs_set(0);   
}
