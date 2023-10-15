#include <ncursesw/ncurses.h>



int main(void) {
    int c;
    int y = 11, x = 11;

    initscr();

    keypad(stdscr, true); // allow arrows
    noecho(); // don't display input
    curs_set(0); // hide cursor

    do {
        clear();
        if (c == KEY_UP) y--;
        else if (c == KEY_DOWN) y++;
        else if (c == KEY_LEFT) x--;
        else if (c == KEY_RIGHT) x++;

        mvaddch(y, x, '@'); // print cursor

    } while ((c = getch()) != 27);

    endwin();
    return 0;
}
