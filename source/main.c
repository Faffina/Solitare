#include "game.h"
#include <ncurses.h>

int main(){
    init();
    card c;
    c.face_up = true;
    for(int s = DIAMONDS; s <= SPADES +1; s++)
        for(int v = ACE; v <= KING; v++)
        {
            c.s = s; c.v = v;
            print_card(s*2, v * 7, c);
        }
    refresh();
    getch();
    end();
    return 0;
}
