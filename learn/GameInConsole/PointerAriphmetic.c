#include <stdio.h>

#define forN(i, n) for(int i = 0; i < n; i++)

int main()  {

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

    puts("-----------------------------------");
    printf("%zd", sizeof(p0_a));


    return 0;
}
