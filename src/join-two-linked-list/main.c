#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* node) {
    if (node == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d->", node->data);
    printList(node->next);
}

struct Node* joinLists(struct Node* head1, struct Node* head2) {
    // both head null return null
    if (!head1 && !head2) return NULL;

    // head1 null return head2
    if (!head1 && head2) return head2;

    // head2 null return head1
    if (head1 && !head2) return head1;

    struct Node* head3 = NULL;
    struct Node* tail3 = NULL;
    while (head1 != NULL) {
        struct Node* newNode = malloc(sizeof(struct Node));
        *newNode = (struct Node){.data = head1->data, .next = NULL};

        if (head3 == NULL) {
            head3 = newNode;
            tail3 = newNode;
        } else {
            tail3->next = newNode;
            tail3 = tail3->next;
        }

        head1 = head1->next;
    }

    while (head2 != NULL) {
        struct Node* newNode = malloc(sizeof(struct Node));
        *newNode = (struct Node){.data = head2->data, .next = NULL};

        tail3->next = newNode;
        tail3 = tail3->next;

        head2 = head2->next;
    }

    return head3;
}

int main(void) {
    struct Node node3 = {.data = 3, .next = NULL};
    struct Node node2 = {.data = 2, .next = &node3};
    struct Node node1 = {.data = 1, .next = &node2};

    struct Node node5 = {.data = 5, .next = NULL};
    struct Node node4 = {.data = 4, .next = &node5};

    struct Node head1 = node1;
    struct Node head2 = node4;

    printList(&head1);
    printList(&head2);

    struct Node* head3 = joinLists(&head1, &head2);
    printList(head3);
}
