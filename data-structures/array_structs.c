#include <stdio.h>

struct Point {
    int x;
    int y;
};

void addPoint(struct Point*);
void printShape(struct Point*);

int main(void) {
    int sides = 3;
    struct Point shape[sides];

    for(int i = 0; i < sides; i++) {
        addPoint(&shape[i]);
    }

    printf("Co-ordinated of the shape:\n");
    for(int i = 0; i < sides; i++) {
        printShape(&shape[i]);
    }
    return 0;
}

void addPoint(struct Point* point) {
    printf("Enter co-ordinates\n");
    printf("x: ");
    scanf("%d", &point->x);
    printf("y: ");
    scanf("%d", &point->y);
}

void printShape(struct Point* point) {
    printf("(%d, %d) ", point->x, point->y);
}
