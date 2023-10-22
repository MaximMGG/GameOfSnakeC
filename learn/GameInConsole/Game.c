#include <ncursesw/ncurses.h>


char map[30][120];
int y, x;



void movement(int c, int *y, int *x) {
        if (c == KEY_UP && map[*y-1][*x] == ' ') (*y)--;
        else if (c == KEY_DOWN && map[*y+1][*x] == ' ') (*y)++;
        else if (c == KEY_LEFT && map[*y][*x-1] == ' ') (*x)--;
        else if (c == KEY_RIGHT && map[*y][*x+1] == ' ') (*x)++;

}

void dungeon(int cols, int rows, char c) {

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
        if (c == KEY_UP && map[*y-1][*x] == ' ') (*y)--;
        else if (c == KEY_DOWN && map[*y+1][*x] == ' ') (*y)++;
        else if (c == KEY_LEFT && map[*y][*x-1] == ' ') (*x)--;
        else if (c == KEY_RIGHT && map[*y][*x+1] == ' ') (*x)++;
}


int main(void) {
    int c;
    int cols, rows;
    int x = 11;
    int y = 11;

    initscr();

    keypad(stdscr, true); // allow arrows
    noecho(); // don't display input
    curs_set(0); // hide cursor
    getmaxyx(stdscr,cols , rows);

    do {
        dungeon(rows, cols);

        movement(c, &y, &x);

        mvaddch(y, x, '@'); // print cursor

    } while((c = getch()) != 27); 

    endwin();
    return 0;
}
