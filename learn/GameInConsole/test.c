#include <stdio.h>


void printVal(char *map[], int x, int y) {
}



int main() {
    int x = 10;
    int y = 10;

    char map[y][x];
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            map[i][j] = 'a';
        }
    }
    char *p = map[0];

    return 0;
}
