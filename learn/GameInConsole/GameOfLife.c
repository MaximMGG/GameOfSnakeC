#include <stdio.h>
#include <malloc.h>

#define forN(i,n) for(int i = 0; i < n; i++)
#define forXY(x, y, w, h) forN(x, w) forN(y, h)
int **grid;


int** array2D(int w, int h) {
    int **tmp = malloc(sizeof(int *) * w);
    forN(a, w) tmp[a] = malloc(sizeof(int) * h);
    return tmp;
}


int main() {

    grid = array2D(10, 10);

    return 0;
}

