#include <ncursesw/ncurses.h>



int dungeon(int cols, int rows, char map[rows][cols]) {

        for(int yy = 0; yy <= rows - 0; yy++){
           for(int xx = 0; xx < cols - 0; xx++){
               mvaddch(yy, xx, '#');
               map[yy][xx] = '#';
           } 
        }

        for(int yy = 11; yy <= rows / 2; yy++){
           for(int xx = 11; xx < cols / 2; xx++){
               mvaddch(yy, xx, ' ');
               map[yy][xx] = ' ';
           } 
        }
        return 1;
}


int main(void) {
    int c;
    int y = 11, x = 11;
    int cols, rows;

    initscr();

    keypad(stdscr, true); // allow arrows
    noecho(); // don't display input
    curs_set(0); // hide cursor
    getmaxyx(stdscr,rows, cols);

    char map[rows][cols];


    do {
        dungeon(rows, cols, map);

        if (c == KEY_UP) y--;
        else if (c == KEY_DOWN) y++;
        else if (c == KEY_LEFT) x--;
        else if (c == KEY_RIGHT) x++;

        mvaddch(y, x, '@'); // print cursor

    } while ((c = getch()) != 27);

    endwin();
    return 0;
}
