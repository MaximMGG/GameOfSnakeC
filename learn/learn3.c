#include <stdio.h>
#include <stdbool.h>



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

    return 0;
}
