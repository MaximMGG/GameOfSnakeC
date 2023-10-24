#include "student.h"


int main() {
    /*
    student st;
    strcpy(st.nm, "John Malkov");
    st.age = 18;
    st.course = 2;
    printStudent(&st);

    pstudent pst;
    pst = malloc(sizeof(student));
    strcpy(pst->nm, "Hemilton Bob");
    pst->age = 28;
    pst->course = 5;
    printStudentVoid(pst);

    int b = 123;

    printStudentVoid(&b);
    */
    student **course;
    int count = 10;
    course = malloc(sizeof(student) * count);

    int c = 0;

    for(int i = 0; i < count; i++){
        course[i] = addStudent(course[i], &c, "Bob", 2, 18 + i);
    }

    printf("%d\n", c);

    for(int i = 0; i < count; i++){
        printf("Name is: %s, course is : %d, age is: %d\n", 
                    course[i]->nm, course[i]->course, course[i]->age);
    }

    return 0;
}
