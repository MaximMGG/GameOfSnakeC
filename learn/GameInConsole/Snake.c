#include <ncursesw/ncurses.h>
#include <pthread.h>
#include <stdbool.h>

#define height 36 
#define width 135 
bool run = true;
bool eat = false;

char map[height][width];


enum Direction{
    UP, DOWN, LEFT, RIGHT  
};

struct Apple {
    int x, y;
}Apple;

struct SnakeCoordinate {
    int x, y;
};

typedef struct {
    struct SnakeCoordinate coord[100];
    int length;
} Snake;

Snake snake;
int step;
struct Apple apple;

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


void putSnakeOnMap() {
    map[snake.coord[0].y][snake.coord[0].x] = '@';
    for(int i = 1; i < snake.length; i++){
        map[snake.coord[i].y][snake.coord[i].x] = '*';
    }
}

void initSnake() {
    snake.length = 3;
    snake.coord[0].x = 13;
    snake.coord[0].y = 13;
    snake.coord[1].x = 13;
    snake.coord[1].y = 14;
    snake.coord[2].x = 13;
    snake.coord[2].y = 15;
}

void DoMove(enum Direction d) {
    int x, y;
    x = snake.coord[0].x;
    y = snake.coord[0].y;

    switch (d) {
        case UP : {
            if (--snake.coord[0].y == snake.coord[1].y) return;
            break;
                  }
        case DOWN : {
            if (++snake.coord[0].y == snake.coord[1].y) return;
            break;
                    }
        case LEFT : {
            if (--snake.coord[0].x == snake.coord[1].x) return;
            break;
                    }
        case RIGHT : {
            if (--snake.coord[0].x == snake.coord[1].x) return;
            break;
                     }
    }

    for(int i = 1; i < snake.length; i++){
        int oldX = x, oldY = y;
        x = snake.coord[i].x;
        y = snake.coord[i].y;
        snake.coord[i].x = oldX;
        snake.coord[i].y = oldY;
    }
    if (eat == true) {
        snake.length++;
        snake.coord[snake.length - 1].x = x;
        snake.coord[snake.length - 1].y = y;
        eat = false;
    }
}

void *moveSnake(void *snake) {
    do {
        clear();
        putSnakeOnMap();
        showMap(); 

        if (step == KEY_DOWN) DoMove(DOWN);
        if (step == KEY_UP) DoMove(UP);
        if (step == KEY_LEFT) DoMove(LEFT);
        if (step == KEY_RIGHT) DoMove(RIGHT);

        if(snake.coord[0].x == apple.x)  eat = true;

    } while(run);
}

int main(void) {
    initscr();

    keypad(stdscr, true); // allow arrows
    noecho(); // don't display input
    curs_set(0); // hide cursor
    Snake snake;
    initSnake();
    initMap();
    pthread_t th1;
    pthread_create(&th1, NULL, *moveSnake, 0);

    do {
        mvprintw(10, 10, "Hello fomr main thread");
        step = getch();
    } while (getch() != 27);
    run = false;

    pthread_join(th1, NULL);
    endwin();
    return 0;
}
