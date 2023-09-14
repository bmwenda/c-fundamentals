#include <stdio.h>

int main() {
    // primitive types
    char c;
    int i;
    double d;

    // derived types
    char string[5];
    int array[5];
    double arrayDouble[5];

    printf("primitive types by size:\n");
    printf("char: %zu\n", sizeof(c));
    printf("int: %zu\n", sizeof(i));
    printf("double: %zu\n", sizeof(d));

    // For derived types, memory size = primitive_size * n
    printf("derived types. n = 5:\n");
    printf("string: %zu\n", sizeof(string));
    printf("int array: %zu\n", sizeof(array));
    printf("double array: %zu\n", sizeof(arrayDouble));

    return 0;
}
