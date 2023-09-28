#include <stdio.h>
#include <limits.h>
#include <math.h>


void getAvarege() {
    unsigned int avarageSuccess = 0;
    unsigned int avarageLooser = 0;
    int result = 0;

    for (int i = 0; i < 10; i++) {
        puts("Please enter number");
        scanf("%d", &result);
        switch (result) {
            case 1: {
                puts("Nice");
                avarageSuccess++;
                break;
            }
            case 2: {
                puts("Uuu");
                avarageLooser++;
                break;
            }
            default: {
                puts("You wrote uncorrect number\nTry agane");
                i--;
            }
        }
    }

    if (avarageSuccess > 8) {
        puts("Extra monye for professore!");
    }
    
}

void getRussian() {
    int arr[] = {1,2,3,4};
    char strArr[] = "Hello";


    int a = *(&strArr + 1) - strArr;

    int lenth = sizeof(strArr) / sizeof(strArr[0]);
    printf("%d\n", a);

    for (int i = 0; strArr[i] != '\0' ; i++) {
        printf("%c", strArr[i]);
    }
    
}



int main(void) {

    float a = 1000 * pow(1 + 0.05, 10);
    printf("%.2f", a);

    return 0;
}

