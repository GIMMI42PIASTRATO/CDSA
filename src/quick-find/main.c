#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
/**
 * This implementation of the quick-find algorithm solve the connectivity problem.
 * Given a pair of integer p q from the standard input the algorithm update the array if the i-th element is equal to the p-th element with the q-th element.
 */
int main(void)
{
    unsigned long p, q;
    unsigned long *id = malloc(sizeof(long) * LONG_MAX);

    for (size_t i = 0; i < LONG_MAX; i++)
    {
        id[i] = i;
    }

    while (scanf("%lu %lu", &p, &q) == 2)
    {
        if (id[p] != id[q])
        {
            for (size_t i = 0; i < LONG_MAX; i++)
            {
                if (id[i] == id[p])
                {
                    id[i] = id[q];
                }
            }
            printf("%lu %lu\n", p, q);
        }
        else
        {
            printf("O(1) Too easy!\n");
        }
    }
}
