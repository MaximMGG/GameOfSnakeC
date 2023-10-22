
#ifndef STUDENT_H_
#define STUDENT_H_  

typedef struct {
    char nm[60];
    unsigned char age;
    unsigned char course;
} student, *pstudent;


void printStudent(student *st);


#endif //STUDENT_H_
