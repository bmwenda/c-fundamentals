#include <stdio.h>

int main() {
    int arr[4] = {1, 2, 3, 4};
    // 'true' because arr is actually a pointer to the address of the first element in the array
    printf("Address of arr[0] == address of arr? %s\n", &arr[0] == arr ? "true" : "false");

    // pointer arithmetic
    int * ptr = arr;
    *(ptr + 1) = 20; // first address of the first element + sizeof(int). References second item
    printf("%d\n", arr[1]); // 20

    *(ptr + 2) = 30; // arr[2] = 30
    printf("%d\n", arr[2]); // 20

    *(ptr + 4) = 40; // warning: array index 4 is past the end of the array (which contains 4 elements) [-Warray-bounds]

    return 0;
}
