#include <stdio.h>
#include "student.h"
//---------------------------------------

void printStudent(student *st) {
    printf("%s, \t%d course, \t%d age\n", st->nm, st->course, st->age);
}



