#include <stdio.h>
#include <windows.h>

unsigned char higth = 40;

#define width 80
#define higth 30

char plate[higth + 1][width + 1];

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

moveLeft() {
    int x = snake.cub[0].x;
    int y = snake.cub[0].y;
    snake.cub[0].x--;
    for (int i = 1; i < snake.length; i++)
    {
        int nx = snake.cub[i].x;
        int ny = snake.cub[i].y;

        snake.cub[i].x = x;
        snake.cub[i].y = y;
        
        x = nx;
        y = ny;
    }
}

moveRight() {
    int x = snake.cub[0].x;
    int y = snake.cub[0].y;
    snake.cub[0].x++;
    for (int i = 1; i < snake.length; i++)
    {
        int nx = snake.cub[i].x;
        int ny = snake.cub[i].y;

        snake.cub[i].x = x;
        snake.cub[i].y = y;
        
        x = nx;
        y = ny;
    }

}

void move() {
    char step;
    scanf("%c", &step);

    switch (step) {
        case 'a' : {moveLeft(); break;}
        case 'd' : {moveRight(); break;}
        case 'w' : {moveUp(); break;}
        case 's' : {moveDown(); break;}
    }
}










int main() {
    initPlate();
    initSnake();
    putSnakeOnPlate();

    showPlate();
}


