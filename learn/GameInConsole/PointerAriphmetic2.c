#include <stdio.h>

#define forN(i, n) for(int i = 0; i < n; i++)

int main() {
    

    unsigned int a[10] = {0x33333333, 0x44444444, 0x55555555, 0x66666666, 0x77777777,
                            0x88888888, 0x99999999, 0xaaaaaaaa, 0xbbbbbbbb, 0xcccccccc}; 

    printf("Element addresses a\n");

    forN(i, 10) printf("0x%08X ", &a[i]);

    printf("\nValue a\n");
    forN(i, 10) printf("0x%08X ", a[i]);

    puts("\n-----------------------------------");

    unsigned int *p0_a, *p5_a;

    p0_a = &a[0];
    p5_a = &a[5];

    printf("Value *p0_a is \t0x%08X and address is \t0x%08X\n", *p0_a, p0_a);
    printf("Value *p5_a is \t0x%08X and address is \t0x%08X\n", *p5_a, p5_a);
    puts("-----------------------------------");

    p0_a++; p5_a++;
    puts("p0_a++; p5_a++");
    printf("Value *p0_a is \t0x%08X and address is \t0x%08X\n", *p0_a, p0_a);
    printf("Value *p5_a is \t0x%08X and address is \t0x%08X\n", *p5_a, p5_a);

    puts("-----------------------------------");
    p0_a--; p5_a--;
    puts("p0_a--; p5_a--");
    printf("Value *p0_a is \t0x%08X and address is \t0x%08X\n", *p0_a, p0_a);
    printf("Value *p5_a is \t0x%08X and address is \t0x%08X\n", *p5_a, p5_a);

    puts("-----------------------------------");
    p0_a += 4; p5_a += 2;
    puts("p0_a+=4; p5_a+=2");
    printf("Value *p0_a is \t0x%08X and address is \t0x%08X\n", *p0_a, p0_a);
    printf("Value *p5_a is \t0x%08X and address is \t0x%08X\n", *p5_a, p5_a);

    puts("-----------------------------------");
    p0_a -= 4; p5_a -= 2;
    puts("p0_a-=4; p5_a-=2");
    printf("Value *p0_a is \t0x%08X and address is \t0x%08X\n", *p0_a, p0_a);
    printf("Value *p5_a is \t0x%08X and address is \t0x%08X\n", *p5_a, p5_a);
    unsigned int n;

    puts("-----------------------------------");

    /*
    n = *++p5_a;
    printf("*++p5_a is 0x%08X\n", n);
    */

    /*
    n = ++*p5_a;
    printf("++*p5_a is 0x%08X\n", n);
    */

    /*
    n = *p5_a++;
    printf("*p5_a++ is 0x%08X\n", n);
    printf("*p5_a is 0x%08X\n", *p5_a);
    */

    /*
    n = (*p5_a)++;
    printf("(*p5_a)++ is 0x%08X\n", n);
    printf("*p5_a is 0x%08X\n", *p5_a);
    */

    unsigned int b[4] = {0x00112233, 0x44556677, 0x8899AABB, 0xCCDDEEFF};

    printf("Element adresses b\n");
    forN(i, 4) printf("0x%08X ", &b[i]);
    puts("\nValue b");
    forN(i, 4) printf("0x%08X ", b[i]);

    puts("-----------------------------");
    unsigned int *p0_b = &b[0], *p2_b = &b[2];
    printf("Value *p0_b is 0x%08X\t p0_b is 0x%08X\n", *p0_b, p0_b);
    printf("Value *p2_b is 0x%08X\t p2_b is 0x%08X\n", *p2_b, p2_b);
    printf("Value p0_b[0] is 0x%08X\n", p0_b[0]);
    printf("Value p0_b[1] is 0x%08X\n", p0_b[1]);
    printf("Value p2_b[0] is 0x%08X\n", p2_b[0]);
    printf("Value p2_b[1] is 0x%08X\n", p2_b[1]);
    printf("Value p2_b[2] is 0x%08X\n", p2_b[2]);
    puts("-----------------------------");
    printf("Value p0_b[-1] is 0x%08X\n", p0_b[-1]);
    printf("Value p2_b[-1] is 0x%08X\n", p2_b[-1]);
    puts("-----------------------------");
    printf("Value *b is 0x%08X\n", *b);
    printf("Value *(b + 2) is 0x%08X\n", *(b + 2));
    puts("-----------------------------");

    printf("Value (unsigned int) (unsigned char*)b is 0x%08X\n", (unsigned int)(unsigned char*)b);
    printf("Value *(unsigned char*)b 0x%02X\n", *(unsigned char*)b);
    printf("Value *(unsigned char*)(b + 1) 0x%02X\n", *(unsigned char*)(b + 1));
    printf("Value *(unsigned char*)(b + 2) 0x%02X\n", *(unsigned char*)(b + 2));
    printf("Value *(((unsigned char*)b) + 1) 0x%02x\n", *(((unsigned char*)b) + 1));
    printf("Value *(((unsigned char*)b) + 2) 0x%02x\n", *(((unsigned char*)b) + 2));
    printf("Value *(((unsigned char*)b) + 3) 0x%02x\n", *(((unsigned char*)b) + 3));
    puts("-----------------------------");
    puts("Bites of b");
    printf("0x%08X\n", (unsigned int) &b[0]);
    forN(i, sizeof(int) * 4) printf("0x%02X ", *(((unsigned char*)b) + i));

    puts("\n-----------------------------");

    int i = 1212390888;
    int *pi = &i;
    char *cpI = (char*)pi;
    forN(i, 4) printf("0x%02X ", *(cpI + i));
     




    return 0;
}
