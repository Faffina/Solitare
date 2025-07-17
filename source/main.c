#include <locale.h>
#include <ncurses.h>

#define CHR_SPADE  u8"♠"
#define CHR_CLUB u8"♣"
#define CHR_HEART u8"♥"
#define CHR_DIAMOND u8"♦"
#define CHR_DOTTED_BOX u8"░"
#define CHR_LINE_H u8"─"
#define CHR_LINE_V u8"│"
#define CHR_CORNER_TL u8"┌"
#define CHR_CORNER_TR u8"┐"
#define CHR_CORNER_BL u8"└"
#define CHR_CORNER_BR u8"┘"
#define CHR_DOT u8"●"

void make_box(int y, int x, int h, int w) {
    if(h < 2 || w < 2)
        return;
    h--; w--;
    for(int i = x + 1; i < x + w; i++){
        mvaddstr(y, i, CHR_LINE_H);
        mvaddstr(y + h, i, CHR_LINE_H);
    }
    for(int i = y + 1; i < y + h; i++) {
        mvaddstr(i, x, CHR_LINE_V);
        mvaddstr(i, x + w, CHR_LINE_V);
    }
    mvaddstr(y, x, CHR_CORNER_TL);
    mvaddstr(y, x + w, CHR_CORNER_TR);
    mvaddstr(y + h, x, CHR_CORNER_BL);
    mvaddstr(y + h, x + w, CHR_CORNER_BR);
}

int main() {
    setlocale(LC_ALL, "");
    initscr();
    raw();
    noecho();
    make_box(0, 0, 5, 7);
    mvaddstr(1, 1, "10");
    mvaddstr(1, 5, CHR_HEART);
    mvaddstr(2, 3, CHR_HEART);
    mvaddstr(3, 1, CHR_HEART);
    mvaddstr(3, 4, "10");
    refresh();
    getch();
    endwin();
}
