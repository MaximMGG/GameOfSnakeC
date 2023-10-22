#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"




int main() {

    /*
    struct student st1;
    strcpy(st1.nm, "Pedro Hulio");
    st1.age = 18;
    st1.course = 2;

    struct student *st1_p;
    st1_p = &st1;

    printf("%s, \t%d course, \t%d age\n", st1_p->nm, st1_p->course, st1_p->age);

    struct student st3;
    struct student *pst3 = &st3; 

    strcpy(pst3->nm, "John Malcov");
    pst3->course = 3;
    pst3->age = 42;
    printStudent(pst3);
    */

    student st = {"Hella Belgio", 22, 5};
    pstudent ps = &st;

    printStudent(ps);
    printf("%zd\n", sizeof(st));

    return 0;
}
