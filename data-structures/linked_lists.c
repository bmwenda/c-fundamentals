#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct Node {
    int x;
    int y;
    struct Node* next;
};

void printNodes(struct Node*);
struct Node* appendNode(struct Node*, struct Node*);
struct Node* createNode(int, int);
void freeMemory(struct Node*);

int main(void) {
    int nodesNum;
    int x, y;
    struct Node* start, * nextNode, * newNode;

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
           appendNode(nextNode, newNode);
        }
    }

    printNodes(start);

    // traverse the linked list, freeing each node's memory
    printf("Freeing memory...");
    freeMemory(start);

    return 0;
}

struct Node* createNode(int x, int y) {
    struct Node* node;
    node = (struct Node*) malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->next = NULL;

    return node;
}

struct Node* appendNode(struct Node* currentNode, struct Node* nextNode) {
    currentNode->next = nextNode;
    return currentNode->next;
}

void printNodes(struct Node* start) {
    struct Node* ptr;

    ptr = start;

    while (ptr != NULL) {
        printf("(%d, %d)\n", ptr->x, ptr->y);
        ptr = ptr->next;
    }
}

void freeMemory(struct Node* currentNode) {
    struct Node* tmp = currentNode;

    while (tmp != NULL) {
        currentNode = tmp;
        tmp = currentNode->next;
        free(currentNode);
    }
}
