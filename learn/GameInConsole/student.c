#include "student.h"
//---------------------------------------

void printStudent(student *st_p) {
    printf("%-30s%d cource\t%d age\n", st_p->nm, st_p->course, st_p->age);
}


void printStudentVoid(void *sam_p) {
    student * ss = (student *) sam_p;
    printf("%-30s%d cource\t%d age\n", ss->nm, ss->course, ss->age);
}

student * addStudent(student *st_p, 
                int *student_counter, 
                char *ch, 
                int cr, 
                int ag) 
{
    st_p = malloc(sizeof(student));
    strcpy(st_p->nm, ch);
    st_p->course = cr;
    st_p->age = ag;
    (*student_counter)++;
    return st_p;
}



void addCourse(student *st){
    st->course++;

}

void addAge(student *st) {
    st->age++;
}

void modifyName(student *st, char *new_name) {
    strcpy(st->nm, new_name);
}


void deltePos(student *st, int pos, int *student_counter) {
    for(int i = pos; i < *student_counter - 1; i++){
        strcpy(st[i].nm, st[i + 1].nm);
        st[i].course = st[i + 1].course;
        st[i].age = st[i + 1].age;
    }
    (*student_counter)--;
}


student_list initStudentList() {
    student_list t = {addCourse, addAge, modifyName, deltePos};
    return t;
}

