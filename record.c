#include <stdio.h>
#include <string.h>

struct student {
    char name [20];
    char student_id [11]; //assuming ten digits
    unsigned mark;
};

//use a desginator .<fieldname> to initialise individual fields
struct group
{
    struct student max;

};

int main(){
    //strcyp(where you want to store, what you want to store)
    struct student new_student;
    int student_mark;


    strcpy(new_student.name, "Name Surname");
    strcpy(new_student.student_id, "13902179");
    printf("enter a mark ");
    scanf("%d",&student_mark);
    new_student.mark = student_mark;

    printf("student name: %s\n", new_student.name);
    printf("student ID: %s\n", new_student.student_id);
    printf("student mark: %u\n", new_student.mark);
    return 0;
}