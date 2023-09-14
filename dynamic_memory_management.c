#include <stdio.h>
#include <stdlib.h>

void mallocDemo(void);
char * allocateString(int);

int main(void) {
    int lengthLight, lengthDark;
    char * strLight, * strDark;

    printf("How many characters do you want str1 and str2 to be respectively?\n");
    scanf("%d %d", &lengthLight, &lengthDark);

    // allocate memory size
    strLight = allocateString(lengthLight);
    strDark = allocateString(lengthDark);

    printf("Enter string1\n");
    scanf("%s", strLight);
    printf("Enter string2\n");
    scanf("%s", strDark);

    printf("Local settings: %s - %s\n", strLight, strDark);

    // release allocated memory
    free(strLight);
    free(strDark);

    return 0;
}

// simple demo of memory allocation in a heap
void mallocDemo(void) {
    int * a, * b;

    a = (int *) malloc(sizeof(int));
    *a = 1;
    printf("Reserved memory address %p and stored value %d\n", a, *a);
    free(a);
    printf("Value at %p is now %d after freeing memory\n", a, *a);

    b = (int *) malloc(sizeof(int));
    *b = 2;
    printf("Reserved memory address %p and stored value %d\n", b, *b);
    free(b);
    printf("Value at %p is now %d after freeing memory\n", b, *b);
}

// allocating space for a given string of size numChars
char * allocateString(int numChars) {
    // we need an addition byte to store the null terminator for the string
    char * ptr = (char *) malloc((numChars + 1) * sizeof(char));

    return ptr;
}
