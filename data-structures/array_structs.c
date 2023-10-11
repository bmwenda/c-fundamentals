#include <stdio.h>
#include<stdlib.h>

struct Point {
    int x;
    int y;
};

void addPoint(struct Point*);
void printShape(struct Point*, int);
void printPoint(struct Point*);

int main(void) {
    int vertices;
    struct Point* polygon;

    printf("Number of vertices: ");
    scanf("%d", &vertices);
    // dynamically allocate an array of pointers
    polygon = (struct Point*) malloc(vertices * sizeof(struct Point));
    for(int i = 0; i < vertices; i++) {
        addPoint(&polygon[i]);
    }

    printf("Co-ordinates of the polygon:\n");
    printShape(polygon, vertices);
    free(polygon);

    return 0;
}

void addPoint(struct Point* point) {
    printf("Enter co-ordinates\n");
    printf("x: ");
    scanf("%d", &(point->x));
    printf("y: ");
    scanf("%d", &(point->y));
}

void printShape(struct Point* polygon, int vertices) {
    for(int i = 0; i < vertices; i++) {
        printPoint(&polygon[i]);
    }
}

void printPoint(struct Point* point) {
    printf("(%d, %d) ", point->x, point->y);
}
