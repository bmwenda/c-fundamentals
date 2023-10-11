#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct node {
    int x;
    int y;
    struct node* next;
} node;

void printNodes(node*);
node* appendNode(node*, node*);
node* createNode(int, int);
void freeMemory(node*);

int main(void) {
    int nodesNum;
    int x, y;
    node* start, * nextNode, * newNode;

    // dynamically create nodes
    printf("Number of nodes: ");
    scanf("%d", &nodesNum);
    for(int i = 0; i < nodesNum; i++) {
        printf("x: ");
        scanf("%d", &x);
        printf("y: ");
        scanf("%d", &y);

        newNode = createNode(x, y);

        if (i == 0) {
            start = nextNode = newNode;
        }
        else {
           nextNode = appendNode(nextNode, newNode);
        }
    }

    printNodes(start);

    // traverse the linked list, freeing each node's memory
    printf("Freeing memory...\n");
    freeMemory(start);

    return 0;
}

node* createNode(int x, int y) {
    node* newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    return newNode;
}

node* appendNode(node* currentNode, node* nextNode) {
    currentNode->next = nextNode;
    return currentNode->next;
}

void printNodes(node* start) {
    node* ptr;

    ptr = start;

    while (ptr != NULL) {
        printf("(%d, %d)\n", ptr->x, ptr->y);
        ptr = ptr->next;
    }
}

void freeMemory(node* currentNode) {
    node* tmp = currentNode;

    while (tmp != NULL) {
        currentNode = tmp;
        tmp = currentNode->next;
        free(currentNode);
    }
}
