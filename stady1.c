#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



int main() {

    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    int i4 = 0;
    int i5 = 0;
    int i6 = 0;

    for (int i = 0; i < 6000000; i++)
    {
        int a = rand() % 6 + 1;
        switch(a) {
            case 1 : {i1++; break;}
            case 2 : {i2++; break;}
            case 3 : {i3++; break;}
            case 4 : {i4++; break;}
            case 5 : {i5++; break;}
            case 6 : {i6++; break;}
        }
    }
        printf("%d\n", i1);
        printf("%d\n", i2);
        printf("%d\n", i3);
        printf("%d\n", i4);
        printf("%d\n", i5);
        printf("%d\n", i6);

    return 0;
}
