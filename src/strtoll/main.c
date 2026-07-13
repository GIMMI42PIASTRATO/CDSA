#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode ListNode, *List;
struct listNode {
    char data;
    List next;
};

void printList(List const node) {
    List nodeCpy = node;

    if (nodeCpy == NULL) return;

    for (; nodeCpy != NULL; nodeCpy = nodeCpy->next) {
        printf("%c ", nodeCpy->data);
    }
}

void printString(char* const s) {
    char* sCpy = s;

    if (sCpy == NULL) return;

    for (; *sCpy != '\0'; sCpy++) {
        printf("%c ", *sCpy);
    }
}

bool printAndCompare(List const node, char* const cmp) {
    List nodeCpy = node;
    char* cmpCpy = cmp;

    bool isEqual = true;

    for (; nodeCpy != NULL && isEqual; nodeCpy = nodeCpy->next, cmpCpy++) {
        if (nodeCpy->data != *cmpCpy) {
            isEqual = false;
        }
    }

    if ((node == NULL) ^ (cmp == NULL)) isEqual = false;

    if (isEqual) {
        printf("[");
        printList(node);
        printf("] == ");
        printString(cmp);
        printf("\tTEST PASSED\n");
    } else {
        printf("[");
        printList(node);
        printf("] != ");
        printString(cmp);
        printf("\tTEST FAILED\n");
    }

    return isEqual;
}

/**
 * Data una stringa s, restituisce una lista di caratteri che contiene tutti
 * e soli i caratteri alfabetici maiuscoli (A - Z) trasformati in minuscoli
 * (a - z) della stringa s nell'ordine in cui occorrono in s.
 *
 * Non considera l'eventualità che la malloc fallisca.
 * Se s == NULL, restituisce NULL.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per
 * compattezza): (1) data s == NULL  restituisce NULL (2) data s == ""
 * restituisce NULL (3) data s == "A" restituisce [a] (4) data s ==
 * "AZbCuu12R" restituisce [a,z,c,r]
 *
 * NOTA: questa funzione compare negli errori di compilazione come
 * "student_stringToList" NOTA: questa funzione viene testata
 * indipendentemente dal vostro main NOTA: viene controllato che questa
 * funzione gestisca correttamente la memoria IMPORTANTE: cercate sempre di
 * far compilare il vostro codice per poter vedere il risultato dei test,
 * anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Given a string s, returns a list of characters containing all and only
 * the uppercase alphabetic characters (A - Z) from string s, converted to
 * lowercase (a - z), in the order in which they appear in s.
 *
 * It does not consider the possibility that malloc may fail.
 * If s == NULL, it returns NULL.
 *
 * EXAMPLES (representing lists without separating characters, for
 * compactness): (1) given s == NULL  returns NULL (2) given s == "" returns
 * NULL (3) given s == "A" returns [a] (4) given s == "AZbCuu12R" returns
 * [a,z,c,r]
 *
 * NOTE: this function appears in compilation errors as
 * "student_stringToList" NOTE: this function is tested independently of
 * your main NOTE: this function also has to correctly handle memory
 * allocation and freeing IMPORTANT: always try to make your code compile so
 * that you can see the test results, even if that means commenting out part
 * of the code of this function
 */
List stringToList(const char* s) {
    List head = NULL;
    List tail = NULL;

    while (*s != '\0') {
        if (isupper(*s)) {
            List newNode = malloc(sizeof(ListNode));
            if (newNode == NULL) return NULL;

            newNode->data = tolower(*s);
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        s++;
    }

    return head;
}

/**
 * Invoca la funzione "stringToList" su uno o più casi a scelta,
 * controllando che il suo effetto come risultato e argomenti rispetti la
 * specifica corretta. Può essere sufficiente anche un unico caso, se
 * sufficientemente generale per individuare quali programmi sono corretti e
 * quali no. Se la funzione è corretta, come ultima cosa deve stampare "TEST
 * PASSED\n". Se invece la funzione non risulta corretta, deve stampare
 * "TEST FAILED\n". NON STAMPARE ALTRO SU STANDARD OUTPUT. Se avete
 * necessità di fare stampe di debug, potete farle su standard error.
 *
 * NOTA: questa funzione compare negli errori di compilazione come
 * "student_main" NOTA: il main viene testato indipendentemente dalla vostra
 * funzione "stringToList" NOTA: viene controllato che questa funzione
 * gestisca correttamente la memoria IMPORTANTE: cercate sempre di far
 * compilare il vostro codice per poter vedere il risultato dei test, anche
 * a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Invokes the "stringToList" function on one or more selected test cases,
 * checking that its effect as result and arguments respects the correct
 * specification. A single test case may be enough, if it sufficiently
 * general to single out which programs are correct and which are not. If
 * the function is correct, as the final step it must print "TEST PASSED\n".
 * If instead the function is not correct, it must print "TEST FAILED\n". DO
 * NOT PRINT ANYTHING ELSE ON STANDARD OUTPUT. If you need to print debug
 * information, use standard error.
 *
 * NOTE: this function appears in compilation errors as "student_main"
 * NOTE: the main is tested independently of your "stringToList" function
 * NOTE: this function also has to correctly handle memory allocation and
 * freeing IMPORTANT: always try to make your code compile so that you can
 * see the test results, even if that means commenting out part of the code
 * of this function
 */
int main(void) {
    bool allPassed = true;

    {
        List node = stringToList("AZbCuu12R");
        allPassed = printAndCompare(node, "azcr");
    }

    {
        List node = stringToList("A");
        allPassed = printAndCompare(node, "a");
    }

    {
        List node = stringToList("");
        allPassed = printAndCompare(node, NULL);
    }

    if (allPassed) {
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
    }
}
