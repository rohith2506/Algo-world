#include <stdio.h>
#include <stdlib.h>

struct Node {
    void *data;
    struct Node *next;
};

void push(struct Node **head_ref, void *new_data, size_t data_size) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = malloc(data_size);
    new_node->next = (*head_ref);
    for(int i=0; i<data_size; i++) {
        *(char *)(new_node->data+i) = *(char *)(new_data + i);
    }
    (*head_ref) = new_node;
}

void printList(struct Node *node, void (* fptr)(void *)) {
    while(node != NULL) {
        (* fptr)(node->data);
        node = node -> next;
    }
}

void printInt(void *n) {
    printf(" %d", *(int *)n);
}

void printFloat(void *n) {
    printf(" %f", *(float *)n);
}

void printChar(void *n) {
    printf(" %c", *(char *)n);
}

int main() {
    struct Node *start = NULL;
    unsigned int_size = sizeof(int);
    int arr[] = {1,2,3,4};
    for(int i=3; i>=0; i--) push(&start, &arr[i], int_size);
    printList(start, printInt);
    printf("\n");
    float arr2[] = {1.0, 2.0, 3.0, 4.0};
    start = NULL;
    for(int i=3; i>=0; i--) push(&start, &arr2[i], sizeof(float));
    printList(start, printFloat);
    printf("\n");
    start = NULL;
    char arr3[] = {'a', 'b', 'c', 'd'};
    for(int i=3; i>=0; i--) push(&start, &arr3[i], sizeof(char));
    printList(start, printChar);
    printf("\n");
    return 0;
}
