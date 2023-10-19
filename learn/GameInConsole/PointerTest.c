#include <stdio.h>

#define forN(i, n) for(int i = 0; i < n; i++)


int main() {

    unsigned int a;
    a = 0xfe340056;
    printf("Value is \t\t0x%08X\n", a);
    unsigned int *p_a;
    p_a = &a;
    printf("Value p_a is \t\t0x%08X\n", p_a);
    printf("Value *p_a is \t\t0x%08X\n", *p_a);

    *p_a = 0xE2222222;

    printf("Value is \t\t0x%08X\n", a);
    puts("-----------------");
    unsigned int b = 0xFAFAFAFA;
    p_a = &b;

    printf("Value p_a is \t\t0x%08X\n", p_a);
    printf("Value *p_a is \t\t0x%08X\n", *p_a);
    puts("-----------------");
    unsigned char uch[10] = {0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC};
    printf("Value uch is \t\t0x%08X\n", uch);
    unsigned char *p_uch = &uch[0];
    forN(a, 10) printf("0x%02X ", p_uch[a]);
    puts("-----------------");
    unsigned int **p_p_a;
    p_a = &a;
    p_p_a = &p_a;
    printf("Value p_p_a is \t\t0x%08X\n", p_p_a);
    printf("Value *p_p_a is \t\t0x%08X\n", *p_p_a);
    printf("Value **p_p_a is \t\t0x%08X\n", **p_p_a);

    **p_p_a = 0xBEBEBEBE;
    printf("Value a is \t\t0x%08X\n", a);

    return 0;

}
