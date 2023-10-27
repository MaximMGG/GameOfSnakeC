#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STUDENT_H_
#define STUDENT_H_  

typedef struct {
    char nm[60];
    unsigned char age;
    unsigned char course;
} student, *pstudent;

typedef struct {
    void (*addCourse) (student *);
    void (*addAge) (student *);
    void (*modifyName) (student *, char *);
    void (*deletePos) (student *, int, int *);
} student_list;

//--------------------------------
void printStudent(student *st_p);
void printStudentVoid(void *sam_p);
student *addStudent(student *st_p, 
                int *student_counter, 
                char *ch, 
                int cr, 
                int ag);

void addCourse(student *);
void addAge(student *);
void modifyName(student *, char *);
void deltePos(student *, int, int*);

student_list initStudentList();
//--------------------------------

#endif //STUDENT_H_
