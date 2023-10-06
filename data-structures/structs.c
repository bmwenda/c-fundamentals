#include <stdio.h>

struct Student {
   char firstname[30];
   char lastname[30];
   int birthYear;
   double grade;

};

void printStudent(struct Student);
void addStudent(struct Student*);

int main(void) {
    struct Student john;
    struct Student jane;

    addStudent(&john);
    addStudent(&jane);

    printStudent(john);
    printStudent(jane);
}

// passing struct by reference
void addStudent(struct Student* stdPtr) {
    printf("Enter student record\n");
    printf("First name: ");
    scanf("%s", (*stdPtr).firstname);
    printf("Last name: ");
    scanf("%s", (*stdPtr).lastname);
    printf("Year of birth: ");
    scanf("%d", &(*stdPtr).birthYear);
    printf("Grade: ");
    scanf("%lf", &(*stdPtr).grade);
    printf("\n");
}

// passing struct by value
void printStudent(struct Student student) {
    printf("Name: %s %s\nAge: %d\nGrade: %.2lf\n", student.firstname, student.lastname, 2023 - student.birthYear, student.grade);
    printf("\n");
}
