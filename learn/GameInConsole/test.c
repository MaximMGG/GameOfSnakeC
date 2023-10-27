#include <stdio.h>
#include <stdlib.h>

#define forN(a, n) for(int a = 0; a < n; a++)

#define forIJ(i, j, n, m) forN(i, n) forN(j, m)
                        

int main() {

    int a;
    int *p_a;
    p_a = &a;

    printf("%x\n", *p_a);

    printf("%d\n", &a);
    printf("%d\n", p_a);

    unsigned int b = *p_a;
    printf("%i\n", b);
    printf("%i\n", *p_a);

    puts("Here0");
    int **p_p_a = &p_a;
    puts("Here0.5");

    p_p_a = malloc(sizeof(*p_a) * 10);
    puts("Here1");

    for(int i = 0; i < 10; i++){
        p_p_a[i] = malloc(sizeof(int) * 10);
    }

    puts("Here2");

    for(int i = 0; i < 10; i++) {
        printf("stepI%d ", i);
        for(int j = 0; j < 10; j++){
            p_p_a[i][j] = i;
            printf("stepJ%d ", j);
        }
    }

    puts("Here3");


    for(int i = 0; i <10; i++) {
        for(int j = 0; j < 10; j++){
            printf("%d", p_p_a[j][i]);
        }
        puts("");
    }
    puts("Here4");

    free(p_p_a);

    char *arr;
    arr = malloc(sizeof(char) * 10);

    forN(i, 10) {
        arr[i] = 'H';
    }

    // arr = "Hello";

     
    forN(i, 10) {
        printf("%c", *arr);
        arr++;
    }

    free(arr);

    char aa = getchar();

    return 0;
}
