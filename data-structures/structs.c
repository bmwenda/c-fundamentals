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
void addStudent(struct Student* studentPtr) {
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
void printStudent(struct Student student) {
    printf("Name: %s %s\nAge: %d\nGrade: %.2lf\n", student.firstname, student.lastname, 2023 - student.birthYear, student.grade);
    printf("\n");
}
