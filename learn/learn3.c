#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <limits.h>
#include <float.h>

void ints();
void doubles();
void maximum();
void stringf();

int main() {

    _Bool bb = false; // for this need <stdbool.h>
    bool b = true;
    int i = 123;
    printf("%d\n", i);
    printf("%#o\n", i);
    printf("%#x\n", i);
    puts("------");

    unsigned int un = 3000000000;
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;

    printf("un = %u, but not %d size = %lld\n", un, un, sizeof(un));
    printf("end = %hd and %d size = %lld\n", end, end, sizeof(end));
    printf("big = %ld, but not %lld size = %lld\n", big, big, sizeof(big));
    printf("verybig = %lld, but not %lld size = %lld\n", verybig, verybig, sizeof(verybig));

    char ch;
    printf("Enter some symbol\n");
    // scanf("%c", &ch);
    // printf("Code of symbol %c is %d", ch, ch);

    ints();
    doubles();
    puts("------------------");
    maximum();
    puts("------------------");
    stringf();


    return 0;
}
#define BLURB "Authentic imitation!"
#define PAGES 336
#define WORDS 65618

void stringf() {
    printf("[%2s]\n", BLURB);
    printf("[%24s]\n", BLURB);
    printf("[%24.5s]\n", BLURB);
    printf("[%-24.5s]\n", BLURB);
    puts("------------------");
    short num = PAGES;
    short mnum = -PAGES;

    printf("num is short and unsigned short: %hd %hu\n", num, num);
    printf("-num is short and unsigned short: %hd %hu\n", mnum, mnum);
    printf("num how int and char: %d %c\n", num, num);
    printf("WORDS how int, short and char : %d %hd %c\n", WORDS, WORDS, WORDS);
    puts("------------------");
    float n1 = 3.0;
    double n2 = 3.0;
    long n3 = 2000000000;
    long n4 = 1234567890;

    printf("%.le %.le %.le %.le\n", n1, n2, n3, n4);
    printf("%ld %ld\n", n3, n4);
    printf("%ld %ld %ld %ld\n",n1, n2, n3, n4);


}

void maximum(){ 
    printf("Maximum integer val is : %d\n", INT_MAX);
    printf("Minimum integer val is : %d\n", INT_MIN);
    // printf("Maximum float val is : %f\n", );
    printf("Minimum integer val is : %d\n", INT_MIN);
}

void ints(){ 

    int32_t me32;
    me32 = 45933945;
    printf("Firstly let's imagen that int32_t is int: ");
    printf("me32 = %d\n", me32);
    printf("Will not make a propose.\n");
    printf("Try to use \"macros\" from file inttypes.h: ");
    printf("me32 = %" PRId32 "\n", me32);

}


void doubles() {
    float aboat = 32000.0f;
    double abet = 2.14e9;
    long double dip = 5.32e-5;

    printf("%f can be written like %e\n", aboat, aboat);
    printf("In %a sixtens\n", abet);
    printf("%Lf could be like %Le\n", dip, dip);
}


