#include <ncursesw/ncurses.h>
#include <pthread.h>

#define height 36 
#define width 135 



char map[height][width];

struct SnakeCoordinate {
    int x, y;
};

typedef struct {
    struct SnakeCoordinate coord[100];
    int length;
} Snake;

void initMap() {
    for(int i = 0; i < width - 1; i++){
        for(int j = 0; j < height - 1; j++){
            if (i == 0 || i == width - 2) map[j][i] = '#';
            else {
                map[j][i] = j == 0 || j == height - 2 ? '#' : ' ';
            }
        }
    }
}


void showMap() {
    for(int i = 0; i < width; i++){
        mvprintw(i, 0, map[i]);
    }
}


void putSnakeOnMap(Snake *snake) {
    map[snake->coord[0].y][snake->coord[0].x] = '@';
    for(int i = 1; i < snake->length; i++){
        map[snake->coord[i].y][snake->coord[i].x] = '*';
    }
}

void initSnake(Snake *snake) {
    snake->length = 3;
    snake->coord[0].x = 13;
    snake->coord[0].y = 13;
    snake->coord[1].x = 13;
    snake->coord[1].y = 14;
    snake->coord[2].x = 13;
    snake->coord[2].y = 15;
}

int main(void) {
    initscr();

    keypad(stdscr, true); // allow arrows
    noecho(); // don't display input
    curs_set(0); // hide cursor
    Snake snake;
    initSnake(&snake);

    initMap();
    do {
        clear();
        showMap(); 
        putSnakeOnMap(&snake);
    } while (getch() != 27);


    endwin();
    return 0;
}
