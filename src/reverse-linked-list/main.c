#include <stdio.h>

typedef struct List List;
struct List {
    char value;
    List* next;
};

List* reverseList(List* head) {
    List* reversed = NULL;  // Pointer to the tail of the list arleady processed
    List* curr = head;      // Pointer to the node to process
    List* temp = head;  // Temporary pointer to the next node, not yet set to
                        // prevent segfault

    while (curr != NULL) {
        temp = curr->next;
        curr->next = reversed;

        reversed = curr;
        curr = temp;
    }

    return reversed;
}

int main(void) { return 0; }
