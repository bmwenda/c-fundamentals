#include <stdio.h>

int main() {
    float floatNum = 1 / 3.0;
    double doubleNum = 1 / 3.0;

    printf("Float: %.50f\n", floatNum);
    printf("Double: %.50lf\n", doubleNum); // more precise

    return 0;
}
