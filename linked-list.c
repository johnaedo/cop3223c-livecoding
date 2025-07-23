#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void addNode(node_t * head, int data) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(node_t));
    if (current->next == NULL) {
        return;
    }
    current->next->data = data;
    current->next->next = NULL;
}

void Push(node_t **head, int data) {
    node_t *newNode = malloc(sizeof(node_t));
    if (newNode == NULL) {
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int Pop(node_t **head) {
    if (*head == NULL) {
        return -1;
    }
    node_t *current = *head;

    int retVal = current->data;
    *head = current->next;
    free(current);
    return retVal;
}

int Dequeue(node_t *head) {
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    

}

void printList(node_t *head) {
    node_t * current = head;
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main(void) {
    srand(time(0));
    node_t *head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->data = 1;
    head->next = NULL;
    addNode(head, (rand() % 6)+1);
    addNode(head, (rand() % 6)+1);
    addNode(head, (rand() % 6)+1);
    printList(head);
    int pushVal = (rand() % 6) + 1;
    printf("Pushing %d\n", pushVal);
    Push(&head, pushVal);
    printList(head);
    printf("Popped %d\n", Pop(&head));
    printList(head);
    printf("Popped %d\n", Pop(&head));
    printList(head);
}