#include <stdio.h>

typedef struct {
   char firstname[30];
   char lastname[30];
   int birthYear;
   double grade;

} student;

void printStudent(student);
void addStudent(student*);

int main(void) {
    student john;
    student jane;

    addStudent(&john);
    addStudent(&jane);

    printStudent(john);
    printStudent(jane);
}

// passing struct by reference
void addStudent(student* studentPtr) {
    // arrow character dereferences the struct pointer
    printf("Enter student record\n");
    printf("First name: ");
    scanf("%s", studentPtr->firstname);
    printf("Last name: ");
    scanf("%s", studentPtr->lastname);
    printf("Year of birth: ");
    scanf("%d", &studentPtr->birthYear);
    printf("Grade: ");
    scanf("%lf", &studentPtr->grade);
    printf("\n");
}

// passing struct by value
void printStudent(student s) {
    printf("Name: %s %s\nAge: %d\nGrade: %.2lf\n", s.firstname, s.lastname, 2023 - s.birthYear, s.grade);
    printf("\n");
}
