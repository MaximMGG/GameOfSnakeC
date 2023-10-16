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

int lives(int **arr, int w, int h) {
    int l = 0;
    forXY(a, b, w, h) if (arr[a][b] == 1) l++;
    return l;
}


int neighborows(int **arr, int w, int h, int x, int y) {
    int n = 0;
    int p[3] = {-1, 0, 1};
    forXY(a, b, 3, 3) {
        int _x = x + p[a];
        int _y = y + p[b];
        if(_x >= 0 && _y >= 0 && _x < w && _y < w)
            if(_x != x && _y != y) 
                if(arr[_x][_y] == 1) n++;
    }
    return n;
}

int** next(int **arr, int w, int h) {
    int **new = array2D(w, h);
    forXY(a, b, w, h) {
        int n = neighborows(arr, w, h, a, b);
        if ((n < 2 || n > 4) && arr[a][b] == 1) 
            new[a][b] = 0;
        else if (n == 3 && arr[a][b] == 0)
            new[a][b] = 1;
        else 
            new[a][b] = arr[a][b];
    }
    return new;
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


    int dl = 0;
    while(1) {

        int live = lives(grid, S, S);

        if (live == 0 || live == dl)
            break;

        puts("-----------------------");
        print(grid, S, S);
        // sleep(1);
        dl = live;
        grid = next(grid, S, S);


    }


    return 0;
}

