#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOK "War and peace"


void task1() {

    float bitsPerSecod;
    float wightOfFile;
    puts("Please enter bits per second and wight of file");
    scanf("%f %f", &bitsPerSecod, &wightOfFile);
    printf("Bits per second is %2.2f and wight of file is %2.2f\n", bitsPerSecod, wightOfFile);
    float bytesPerSecond = bitsPerSecod / 8;
    float timeLoading = wightOfFile / bytesPerSecond;
    printf("Time of loading is %1.2f\n", timeLoading);
}

void task2() {
    char name[10];
    char surename[10];
    int nameLength;
    int surenameLength;
    puts("Please enter name and surename");
    scanf("%s %s", name, surename);
    nameLength = strlen(name);
    surenameLength = strlen(surename);
    printf("%s %s\n", name, surename);
    printf("%*d %*d\n", nameLength, nameLength, surenameLength, surenameLength);
    printf("%.*d %.*d\n", nameLength, nameLength, surenameLength, surenameLength);

}


int main() {

    int b = 0x8A;

    float cost = 12.99;
    float percent = 80.0; 
    printf("This book \"%s\" cost $%2.2f.\n", BOOK, cost);
    printf("And it is %2.0f%% of price.\n", percent);
    puts("----------------------------------------------------");

    printf("0x%04X\n", b);
    printf("%30s\n", "Hello");
    puts("----------------------------------------------------");

    int a1;
    float a2;
    double a3;
    char a4[10];
    char a5[10];
    int a6;

    // scanf("%d", &a1);
    // printf("%d\n", a1);
    //
    // scanf("%f", &a2);
    // scanf("%lf", &a3);
    // printf("%2.2f %e\n", a2, a3);
    // scanf("%s", a4);
    // printf("%s\n", a4);
    // scanf("%s %d", a5, &a6);
    // printf("%s %d", a5, a6);
    // scanf("%d", &a6);
    // printf("%d\n", a6);
    // int width = 12;
    // int aa = 123;
    // printf("%*d", width, aa);

    // task1();
    task2();


    return 0;
}
