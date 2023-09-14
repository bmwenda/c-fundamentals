#include <stdio.h>

int creatingPointers();
int dereferencingPointers();
void swapValuesByReference(int *, int *);

int main(void) {
    creatingPointers();
    printf("\n");
    dereferencingPointers();
    printf("\n");
    int a = 10;
    int b = 20;
    swapValuesByReference(&a, &b);
    printf("The swapped values are: a => %d, b => %d\n", a, b);
}

int creatingPointers() {
    int i = 10;
    char c = 'c';
    double d = 20.234;

    int * ptrI = &i;
    char * ptrC = &c;
    double * ptrD = &d;

    if (sizeof(ptrI) == 4) {
        printf("System is 32bit\n");
    } else if (sizeof(ptrI) == 8) {
        printf("System is 64bit\n");
    } else {
        printf("Weird architecture!\n");
    }

    printf("Address of i: %p\n", ptrI);
    printf("Address of c: %p\n", ptrC);
    printf("Address of d: %p\n", ptrD);

    return 0;
}

int dereferencingPointers() {
    int a = 5;
    int * ptrA = &a;

    // deference i.e read value of throught the pointer
    printf("Value of a through the pointer: %d\n", *ptrA);

    // replace value of a through pointer
    *ptrA = *ptrA * 2;
    printf("New value of a: %d\n", *ptrA);

    return 0;
}

void swapValuesByReference(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
