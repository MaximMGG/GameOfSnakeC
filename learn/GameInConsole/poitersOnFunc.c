#include "student.h"


int main() {

    /*
    unsigned int *print_str_addr;
    print_str_addr = (unsigned int *)print_str;
    void (*print_str_p) (const char *);
    print_str_p = (void *) print_str_addr;
    print_str_p("HEllo");
    */

    student **st;
    st = malloc(sizeof(student) * 20);
    int counter = 0;
    for(int i = 0; i < 20; i++){
        st[i] = addStudent(st[i], &counter, "Bob", i, 10 + i);
    }

    for(int i = 0; i < 20; i++){
        printStudent(st[i]);
    }

    student_list st_list = initStudentList();

    st_list.modifyName(st[0], "John");
    printf("%s\n", st[0]->nm);

    st_list.addAge(st[1]);
    printf("%d\n", st[1]->age);

    st_list.addCourse(st[2]);
    printf("%d\n", st[2]->course);

    free(st);
    return 0;
}







