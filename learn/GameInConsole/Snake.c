#include <ncursesw/ncurses.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define height 36 
#define width 135 
bool run = true;
bool eat = false;
bool appleExist = false;

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
struct Apple apple;
int count = 0;

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
    apple.y = (int) rand() % (height - 4) + 2;
    apple.x = (int) rand() % (width - 4) + 2;
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
            if (snake.coord[0].y - 1 == snake.coord[1].y) {
                ++snake.coord[0].y;
            } else {
            --snake.coord[0].y;
            }
            break;
        }
        case DOWN : {
            if (snake.coord[0].y + 1 == snake.coord[1].y) {
                --snake.coord[0].y;
            } else {
                ++snake.coord[0].y;
            }
            break;
        }
        case LEFT : {
            if (snake.coord[0].x - 1 == snake.coord[1].x) {
                ++snake.coord[0].x;
            } else {
                --snake.coord[0].x;
            }
            break;
        }
        case RIGHT : {
            if (snake.coord[0].x + 1 == snake.coord[1].x) {
                --snake.coord[0].x;
            } else {
                ++snake.coord[0].x;
            }
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

    if (apple.x == snake.coord[0].x && apple.y == snake.coord[0].y) {
        snake.length++;
        snake.coord[snake.length - 1].x = x;
        snake.coord[snake.length - 1].y = y;
        eat = true;
        count++;
    } else {
        map[y][x] = ' ';
    }


}

void putAppleOnMap() {
    if (eat == true) {
       srand(time(NULL));
       map[apple.y][apple.x] = ' ';
       apple.x = rand() % (width - 4) + 2;
       apple.y = rand() % (height - 4) + 2;
       map[apple.y][apple.x] = '$';
       eat = false;
    }
}

void printCount() {
    mvprintw(0, 140, "Score is : %d", count);
}

void checkWall() {
    if (map[snake.coord[0].y][snake.coord[0].x] == '#') {
        run = false;
    }
}

void checkBodyCross() {
    int y = snake.coord[0].y;
    int x = snake.coord[0].x;
    for(int i = 1; i < snake.length; i++){
        if (y == snake.coord[i].y && x == snake.coord[i].x) { 
            run = false;
            break;
        }
    }

}

void moveSnake() {
    short step = KEY_UP;
    short prevStep = KEY_UP;
    do {
        clear();
        putSnakeOnMap();
        putAppleOnMap();
        showMap();
        printCount();

        step = getch();

        if (step == KEY_DOWN) {DoMove(DOWN); prevStep = step;}
        else if (step == KEY_UP) {DoMove(UP); prevStep = step;}
        else if (step == KEY_LEFT) {DoMove(LEFT); prevStep = step;}
        else if (step == KEY_RIGHT) {DoMove(RIGHT);prevStep = step;}
        else {
            if (prevStep == KEY_DOWN) DoMove(DOWN);
            else if (prevStep == KEY_UP) DoMove(UP);
            else if (prevStep == KEY_LEFT) DoMove(LEFT);
            else if (prevStep == KEY_RIGHT) DoMove(RIGHT);
        }
        checkWall();
        checkBodyCross();
        if (step == 27) {
            run = false;
        }
    
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
    moveSnake();


    if (run == false) {
        puts("Your are loose, next time");
    }

    endwin();
    return 0;
}
