#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h> // for sleep

#define forN(i,n) for(int i = 0; i < n; i++)
#define forXY(x, y, w, h) forN(x, w) forN(y, h)

#define nL puts("")


#define S 10

int **grid;


int** array2D(int w, int h) {
    int **tmp = malloc(sizeof(int *) * w);
    forN(a, w) tmp[a] = malloc(sizeof(int) * h);
    return tmp;
}


int** next(int **arr, int w, int h) {

}



void print(int **arr, int  w, int h) {
    forN(a, w) {
        forN(b, h) {
            printf("%c ", arr[a][b] == 1 ? '#' : ' ');
        }
        nL;
    }
}

int main() {

    srand(time(0));
    grid = array2D(S, S);
    forXY(a, b, S, S) {
        grid[a][b] = rand() % 2;
    }


    while(1) {
        print(grid, S, S);
        sleep(1);
        grid = next(grid);
    }


    return 0;
}

