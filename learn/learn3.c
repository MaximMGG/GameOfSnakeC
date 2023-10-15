#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

void ints();
void doubles();

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
    printf("big = %ld, but not %hd size = %lld\n", big, big, sizeof(big));
    printf("verybig = %lld, but not %ld size = %lld\n", verybig, verybig, sizeof(verybig));

    char ch;
    printf("Enter some symbol\n");
    // scanf("%c", &ch);
    // printf("Code of symbol %c is %d", ch, ch);

    ints();
    doubles();


    return 0;
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


