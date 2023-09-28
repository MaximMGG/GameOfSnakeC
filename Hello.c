#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void guessNumber(void);
int isCorrect(int a, int b);


int main(void) {

    guessNumber();


    return 0;
}


void guessNumber(void) {

    int answer;
    int guess;
    int response;

    do {

        answer = 1 + rand() % 1000;

        puts ( "I have number between 1 and 1000\n"
                "Can you guess my number\n"
                "Please type your first guess."
                );
        printf("%s", "? ");
        scanf("%d", &guess);


        while (!isCorrect(guess, answer))
            scanf("%d", &guess);

        puts ("\nExcelent, you guessed number\n"
                "Do you like to play agane?\n");
        printf("%s", "Please type (y=yes, n=no)?");
        scanf("%d", &response);

        puts ("");
    } while (response == 1);
    printf("%s", "Sanks for having us\n");
    printf("%s", "gcc --version\0\n");
}


int isCorrect(int a, int b) {

    if (a == b)
        return 1;

    if (a < b) {
        printf("%s", "To low, try agane\n");
    } else {
        printf("%s", "To high, try agane\n");
    }

    return 0;
}
