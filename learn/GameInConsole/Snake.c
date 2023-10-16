#include <ncursesw/ncurses.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

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
    for(int i = 0; i < height - 1; i++){
        for(int j = 0; j < width - 1; j++){
            if (i == 0 || i == height - 2) map[i][j] = '#';
            else {
                map[i][j] = j == 0 || j == width - 2 ? '#' : ' ';
            }
        }
    }
}

void initApple() {
    srand(time(NULL));
    apple.y = rand() % height;
    apple.x = rand() % width;
    map[apple.y][apple.x] = '$';
}


void showMap() {
    for(int i = 0; i < height; i++){
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
void putAppleOnMap() {
    if (eat == false) return;
    srand(time(NULL));
    map[apple.y][apple.x] = ' ';
    apple.x = rand() % width;
    apple.y = rand() % height;
    map[apple.y][apple.x] = '$';
}

void *moveSnake() {
    do {
        clear();
        putSnakeOnMap();
        putAppleOnMap();
        showMap();
    
        if (step == KEY_DOWN) DoMove(DOWN);
        else if (step == KEY_UP) DoMove(UP);
        else if (step == KEY_LEFT) DoMove(LEFT);
        else if (step == KEY_RIGHT) DoMove(RIGHT);
    
        if(snake.coord[0].x == apple.x
                && snake.coord[0].y == apple.y)  eat = true;
        Sleep(100);
    } while(run);
}

int main(void) {
    initscr();

    keypad(stdscr, true); // allow arrows
    noecho(); // don't display input
    curs_set(0); // hide cursor
    timeout(0);

    initSnake();
    initMap();
    initApple();
    step = KEY_UP;

    pthread_t th1;
    pthread_create(&th1, NULL, *moveSnake, 0);

    do {
        char prevStep = step;
        step = getch();
        if (step != KEY_UP || step != KEY_DOWN || step != KEY_LEFT || step != KEY_RIGHT)
            step = prevStep;
    } while (getch() != 27);

    run = false;

    pthread_join(th1, NULL);
    endwin();
    return 0;
}
