#include <stdio.h>
#include "student.h"
#include <string.h>
#include <stdlib.h>


typedef struct{
    int *arr;
    unsigned int len;
} Arr_int;



//-----------------------------
void Arr_int_allocMemory(Arr_int *ai);
void Arr_int_freeMemory(Arr_int *ai);
void print_char(const char *ch);
void print_str(const char *str);
void print_int(const int *arr, unsigned int len);
//-----------------------------
int main(){

    char str1[30] = {};
    strcpy(str1, "Hello, World!!!");
    int arr[5] = {1, 2, 3, 4, 5};

    // print_str(str1);
    // print_str("Wowowowoy");
    // print_char("qwerqwerqwer!@");
    // print_int(arr, 5);

    Arr_int ar;
    ar.len = 5;
    Arr_int_allocMemory(&ar);

    for(int i = 0; i < ar.len; i++){
        ar.arr[i] = i;
    }
    // print_int(ar.arr, ar.len);
    Arr_int_freeMemory(&ar);

    float sum;
    MySum(2.3, 1.4, &sum);
    printf("%f\n", sum);

    return 0;
}


void print_char(const char *ch) {
    int i = 0;
    while(ch[i]) {
        printf("%c\n", ch[i]);
        i++;
    }
}

void Arr_int_allocMemory(Arr_int *ai){
    ai->arr = malloc(sizeof(int) * ai->len);
}
void Arr_int_freeMemory(Arr_int *ai) {
    free(ai);
}

void print_int(const int *arr, unsigned int len) {
    for(int i = 0; i < len; i++){
        printf("%d", arr[i]);
    }
    puts("");
}


void print_str(const char *str) {

    // for(int i = 0; str[i] != '\0'; i++){
    //     printf("%c", str[i]);
    // }
    //
    // puts("");
    
    // printf("%s\n", str);
}
