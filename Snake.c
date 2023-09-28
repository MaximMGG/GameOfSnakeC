#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>


unsigned char higth = 40;

#define width 80
#define higth 30

char plate[higth + 1][width + 1];
bool loose = false;

typedef struct CubeOfSnake {
    int x, y;
} cube;

typedef struct Snake {
    cube cub[100];
    int length;
} Snake;

Snake snake;

void initPlate() {
    for (int i = 0; i < higth; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == higth - 1) {
                plate[i][j] = '#';
            } else {
                plate[i][j] = j == 0 || j == width - 1 ? '#' : ' ';
            }
        }
    }
}

void showPlate() {
    for (int i = 0; i < higth; i++) {
        printf("%s", plate[i]);
        if (i != higth - 1) {
            printf("\n");
        }
    }
}

void initSnake() {
    snake.length = 3;
    snake.cub[0].x = width / 2;
    snake.cub[0].y = higth / 2;

    snake.cub[1].x = width / 2 + 1;
    snake.cub[1].y = higth / 2;

    snake.cub[2].x = width / 2 + 2;
    snake.cub[2].y = higth / 2;

}

void putSnakeOnPlate() {
    for (int i = 0; i < snake.length; i++) {
        if (i == 0) {
            plate[snake.cub[i].y][snake.cub[i].x] = '@';
        } else {
            plate[snake.cub[i].y][snake.cub[i].x] = '*';
        }
    }
}

void hideTail(int x, int y) {
    plate[y][x] = ' ';
}

void moveLeft() {
    int x = snake.cub[0].x;
    int y = snake.cub[0].y;
    snake.cub[0].x--;
    if (snake.cub[0].x == 0) {
        loose = true;
        return;
    }
    if (snake.cub[0].x == snake.cub[1].x) {
        snake.cub[0].x++;
        return;
    }
    for (int i = 1; i < snake.length; i++)
    {
        int nx = snake.cub[i].x;
        int ny = snake.cub[i].y;

        snake.cub[i].x = x;
        snake.cub[i].y = y;
        
        x = nx;
        y = ny;
    }
    hideTail(x, y);
}

void moveRight() {
    int x = snake.cub[0].x;
    int y = snake.cub[0].y;
    snake.cub[0].x++;
    if (snake.cub[0].x == width - 1) {
        loose = true;
        return;
    }
    if (snake.cub[0].x == snake.cub[1].x) {
        snake.cub[0].x--;
        return;
    }
    for (int i = 1; i < snake.length; i++)
    {
        int nx = snake.cub[i].x;
        int ny = snake.cub[i].y;

        snake.cub[i].x = x;
        snake.cub[i].y = y;
        
        x = nx;
        y = ny;
    }
    hideTail(x, y);
}

void moveUp() {
    int x = snake.cub[0].x;
    int y = snake.cub[0].y;
    snake.cub[0].y--;
    if (snake.cub[0].y == 0) {
        loose = true;
        return;
    }
    if (snake.cub[0].y == snake.cub[1].y) {
        snake.cub[0].y++;
        return;
    }

    for (int i = 1; i < snake.length; i++)
    {
        int nx = snake.cub[i].x;
        int ny = snake.cub[i].y;

        snake.cub[i].x = x;
        snake.cub[i].y = y;
        
        x = nx;
        y = ny;
    }
    hideTail(x, y);
}

void moveDown() {
    int x = snake.cub[0].x;
    int y = snake.cub[0].y;
    snake.cub[0].y++;
    if (snake.cub[0].y == higth - 1) {
        loose = true;
        return;
    }
    if (snake.cub[0].y == snake.cub[1].y) {
        snake.cub[0].y--;
        return;
    }

    for (int i = 1; i < snake.length; i++)
    {
        int nx = snake.cub[i].x;
        int ny = snake.cub[i].y;

        snake.cub[i].x = x;
        snake.cub[i].y = y;
        
        x = nx;
        y = ny;
    }
    hideTail(x, y);
}

void move() {
    char step;
    // scanf("%c", &step);
    step = getch();

    while (step != 'q' || !loose)
    {

        switch (step) {
        case 'a': {
            moveLeft();
            break;
        }
        case 'd': {
            moveRight();
            break;
        }
        case 'w': {
            moveUp();
            break;
        }
        case 's': {
            moveDown();
            break;
        }
        }
        putSnakeOnPlate();
        system("cls");
        showPlate();
        // scanf("%c", &step);
        step = getch();
    }
}










int main() {
    initPlate();
    initSnake();
    putSnakeOnPlate();

    showPlate();
    move();
}


