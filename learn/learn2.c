#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define DAYS_IN_YEAR 365


void printMyYearToDays(int a);
void jolly();
void deny();
void MultiplyToes();
void printSmile(int a);
void one_tree();
void two();

int main(void) {

    // int j = 30;
    // while (j > 0) {
    //     for(int i = 0; i < 3; i++){
    //         printf(".");
    //         Sleep(50);
    //     }
    //     for(int i = 0; i < 3; i++) {
    //         printf("\b \b");
    //         Sleep(50);
    //     }
    //     j--;
    // }

    int x, y;
    x = 10;
    y = 5;
    y = x + y;
    x = x * y;

    printf("%d %d\n", x, y);

    printMyYearToDays(29);

    for(int i = 0; i < 3; i++){
        jolly();
    }
    deny();

    MultiplyToes();
    printSmile(3);
    printSmile(2);
    printSmile(1);
    printf("Let's go\n");
    one_tree();
    printf("We done\n");

        

    return 0;


}

void one_tree() {
    puts("One");
    two();
    puts("Three");

}

void two() {
    puts("Two");
}

void printSmile(int a) {
    for(int i = 0; i < a; i++){
        printf("Smile!");
    }
    puts("");
}

void MultiplyToes(){
    int toes;
    toes = 10;
    printf("toes = %d, dable toes = %d, sqrd toes = %d\n", toes, toes * 2, toes * toes);

}

void jolly(){ 

    puts("He is funny");
}

void deny() {
    puts("No one can't disagry with this");
}

void printMyYearToDays(int a) {

    printf("%d - years this is %d days\n", a, a * DAYS_IN_YEAR);

}







