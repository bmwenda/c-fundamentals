#include <stdio.h>
#include<stdlib.h>

typedef struct {
    int x;
    int y;
} point;

void addPoint(point*);
void printShape(point*, int);
void printPoint(point*);

int main(void) {
    int vertices;
    point* polygon;

    printf("Number of vertices: ");
    scanf("%d", &vertices);
    // dynamically allocate an array of pointers
    polygon = (point*) malloc(vertices * sizeof(point));
    for(int i = 0; i < vertices; i++) {
        addPoint(&polygon[i]);
    }

    printf("Co-ordinates of the polygon:\n");
    printShape(polygon, vertices);
    free(polygon);

    return 0;
}

void addPoint(point* p) {
    printf("Enter co-ordinates\n");
    printf("x: ");
    scanf("%d", &(p->x));
    printf("y: ");
    scanf("%d", &(p->y));
}

void printShape(point* polygon, int vertices) {
    for(int i = 0; i < vertices; i++) {
        printPoint(&polygon[i]);
    }
}

void printPoint(point* p) {
    printf("(%d, %d) ", p->x, p->y);
}
