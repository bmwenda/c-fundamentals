#include <stdio.h>

int main() {
    int num = 2147483645;

    // this will overflow num into -ve values
    for(int i = 0; i < 8; i++) {
        printf("%d\n", num);
        num = num + i;
    }
    return 0;
}
