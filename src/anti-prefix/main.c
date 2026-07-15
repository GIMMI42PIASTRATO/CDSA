#include <stdio.h>

typedef struct listNode ListNode, *List;
struct listNode {
    char data;
    List next;
};

/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */

#include <stdbool.h>
#include <stdlib.h>

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

List stringToList(char* str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    List head = NULL;
    List tail = NULL;

    while (*str != '\0') {
        List newNode = malloc(sizeof(ListNode));
        if (newNode == NULL) return NULL;

        *newNode = (ListNode){.data = *str, .next = NULL};

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }

        str++;
    }

    return head;
}

bool equalList(List l, List cmp) {
    bool isEqual = true;

    while (l != NULL && isEqual) {
        if (cmp == NULL || l->data != cmp->data) {
            isEqual = false;
        }

        l = l->next;
        cmp = l->next;
    }

    return isEqual;
}

void freeList(List head) {
    if (head == NULL) return;

    while (head != NULL) {
        List temp = head->next;
        free(head);
        head = temp;
    }
}

/**
 * Date due liste di caratteri l ed r, restituire una nuova lista p (senza
 * modificare le liste l ed r) che contenga il più lungo prefisso di l per
 * cui nessun suo carattere ha un carattere uguale nella posizione
 * corrispondente di r.
 *
 * Si definisce "prefisso" di una lista una qualunque sotto-lista di nodi
 * dall'inizio. Non considera l'eventualità che la malloc fallisca.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per
 * compattezza): (1) date l=[] e s=[], restituisce p=[] (2) date l=[] e
 * s=[p,i,p,p,o], restituisce p=[] (3) date l=[p,i,p,p,o] e s=[],
 * restituisce p=[p,i,p,p,o] (4) date l=[p,i,p,p,o] e s=[p,i,p,p,o],
 * restituisce p=[] (5) date l=[s,u,p,e,r,p,i,p,p,o] e s=[p,l,u,t,o],
 * restituisce p=[s,u,p,e,r,p,i,p,p,o] (6) date l=[p,l,u,t,o] e
 * s=[s,u,p,e,r,p,i,p,p,o], restituisce p=[p,l,u,t,o] (7) date
 * l=[s,u,p,e,r,p,i,p,p,o] e s=[p,i,p,p,o], restituisce p=[s,u], perché la p
 * seguente è in comune (8) date l=[p,i,p,p,o] e s=[s,u,p,e,r,p,i,p,p,o],
 * restituisce p=[p,i], perché la p seguente è in comune
 *
 * NOTA: questa funzione compare negli errori di compilazione come
 * "student_antiPrefix" NOTA: questa funzione viene testata
 * indipendentemente dal vostro main NOTA: viene controllato che questa
 * funzione gestisca correttamente la memoria IMPORTANTE: cercate sempre di
 * far compilare il vostro codice per poter vedere il risultato dei test,
 * anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Given two character lists l and r, return a new list p (without
 * modifying lists l and r) containing the longest prefix of l such
 * that none of its characters has an identical character in the
 * corresponding position of r.
 *
 * A "prefix" of a list is defined as any sublist of nodes starting from the
 * beginning. It does not consider the possibility that malloc may fail.
 *
 * EXAMPLES (representing lists without separating characters, for
 * compactness): (1) given l=[] and s=[], returns p=[] (2) given l=[] and
 * s=[p,i,p,p,o], returns p=[] (3) given l=[p,i,p,p,o] and s=[], returns
 * p=[p,i,p,p,o] (4) given l=[p,i,p,p,o] and s=[p,i,p,p,o], returns p=[] (5)
 * given l=[s,u,p,e,r,p,i,p,p,o] and s=[p,l,u,t,o], returns
 * p=[s,u,p,e,r,p,i,p,p,o] (6) given l=[p,l,u,t,o] and
 * s=[s,u,p,e,r,p,i,p,p,o], returns p=[p,l,u,t,o] (7) given
 * l=[s,u,p,e,r,p,i,p,p,o] and s=[p,i,p,p,o], returns p=[s,u], because the
 * following p is shared (8) given l=[p,i,p,p,o] and
 * s=[s,u,p,e,r,p,i,p,p,o], returns p=[p,i], because the following p is
 * shared
 *
 * NOTE: this function appears in compilation errors as "student_antiPrefix"
 * NOTE: this function is tested independently of your main
 * NOTE: this function also has to correctly handle memory allocation and
 * freeing IMPORTANT: always try to make your code compile so that you can
 * see the test results, even if that means commenting out part of the code
 * of this function
 */
List antiPrefix(List l, List r) {
    List head = NULL;
    List tail = NULL;
    bool equal = false;
    for (; !equal && l != NULL; l = l->next) {
        if (r != NULL) {
            if (l->data == r->data) {
                equal = true;
            } else {
                List newNode = malloc(sizeof(ListNode));
                if (newNode == NULL) return NULL;

                *newNode = (ListNode){.data = l->data, .next = NULL};

                if (head == NULL) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = tail->next;
                }
            }

            r = r->next;
        } else {
            List newNode = malloc(sizeof(ListNode));
            if (newNode == NULL) return NULL;

            *newNode = (ListNode){.data = l->data, .next = NULL};

            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
    }

    return head;
}

/**
 * Invoca la funzione "antiPrefix" su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * NON STAMPARE ALTRO SU STANDARD OUTPUT.
 * Se avete necessità di fare stampe di debug, potete farle su standard error.
 *
 * NOTA: questa funzione compare negli errori di compilazione come
 * "student_main" NOTA: il main viene testato indipendentemente dalla vostra
 * funzione "antiPrefix" NOTA: viene controllato che questa funzione gestisca
 * correttamente la memoria IMPORTANTE: cercate sempre di far compilare il
 * vostro codice per poter vedere il risultato dei test, anche a costo di
 * commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Invokes the "antiPrefix" function on one or more selected test cases,
 * checking that its effect as result and arguments respects the correct
 * specification. A single test case may be enough, if it sufficiently general
 * to single out which programs are correct and which are not. If the function
 * is correct, as the final step it must print "TEST PASSED\n". If instead the
 * function is not correct, it must print "TEST FAILED\n". DO NOT PRINT ANYTHING
 * ELSE ON STANDARD OUTPUT. If you need to print debug information, use standard
 * error.
 *
 * NOTE: this function appears in compilation errors as "student_main"
 * NOTE: the main is tested independently of your "antiPrefix" function
 * NOTE: this function also has to correctly handle memory allocation and
 * freeing IMPORTANT: always try to make your code compile so that you can see
 * the test results, even if that means commenting out part of the code of this
 * function
 */
int main() {
    bool allPassed = true;

    {
        List head = antiPrefix(NULL, NULL);
        if (head != NULL) allPassed = false;
    }

    {
        ListNode node1 = {.data = 'p', .next = NULL};
        List head = antiPrefix(&node1, NULL);
        if (head->data != 'p') allPassed = false;
        free(head);
    }

    {
        ListNode node2 = {.data = 'p', .next = NULL};
        List head = antiPrefix(NULL, &node2);
        if (head != NULL) allPassed = false;
    }

    {
        ListNode node1 = {.data = 'p', .next = NULL};
        ListNode node2 = {.data = 't', .next = NULL};
        List head = antiPrefix(&node1, &node2);
        if (head->data != 'p') allPassed = false;
        free(head);
    }

    {
        List l = stringToList("superpippo");
        List r = stringToList("pluto");
        List cmp = stringToList("superpippo");

        List head = antiPrefix(l, r);
        if (!equalList(head, cmp)) {
            allPassed = false;
            printf("I'm here ofc");
        }
        freeList(l);
        freeList(r);
        freeList(cmp);
        freeList(head);
    }

    if (allPassed) {
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
    }

    return 0;
}
