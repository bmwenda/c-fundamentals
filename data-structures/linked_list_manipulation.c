#include <stdio.h>
#include <stdlib.h>

typedef struct digit {
    int num;
    struct digit* next;
} digit;

digit* readNumber(void);
digit* createDigit(int);
digit* append(digit*, digit*);
void printNumber(digit*);
int countRedundant(digit*);
digit* prepend(digit*, digit*);
int search(digit*, int);
void freeNumber(digit*);

// create a digit of infinite length using linked list
// duplicate linked list
// search linked list

int main(void) {
    digit* start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedundant(start));

    freeNumber(start);

    return 0;
}

digit* readNumber(void) {
    char c;
    int d;
    digit* start, * end, * newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c - 48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

digit* createDigit(int dig) {
    digit* ptr;
    ptr = (digit*) malloc(sizeof(digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

digit* append(digit* end, digit* newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(digit* start) {
    digit* ptr = start;
    while (ptr != NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(digit* start) {
    digit* ptr = start;
    digit* tmp;
    while (ptr != NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

int search(digit* start, int num) {
    digit* ptr = start;

    while (ptr != NULL) {
        if (ptr->num == num) {
            return 1;
        }
        else {
            ptr = ptr->next;
        }
    }
    return 0;
}

digit* prepend(digit* start, digit* newDigit) {
    newDigit->next = start;
    return newDigit;
}

int countRedundant(digit* start) {
    digit* ptr = start;
    digit* newDigit;
    digit* startUnique = start;
    int redundant = 0;

    if (start != NULL) {
        startUnique = createDigit(start->num);
        ptr = ptr->next;
    }

    while (ptr != NULL) {
        newDigit = createDigit(ptr->num);
        if (search(startUnique, ptr->num)) {
            redundant++;
        }
        else {
            startUnique = prepend(startUnique, newDigit);
        }
        ptr = ptr->next;
    }

    return redundant;
}
