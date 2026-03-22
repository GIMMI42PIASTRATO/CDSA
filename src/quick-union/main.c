#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int p, q, i, j;
    int *id = malloc(sizeof(int) * INT_MAX);

    for (i = 0; i < INT_MAX; i++)
    {
        id[i] = i;
    }

    while (scanf("%d %d", &p, &q) == 2)
    {
        for (i = p; i != id[i]; i = id[p])
            ;
        for (j = q; j != id[j]; j = id[q])
            ;
        if (i == j)
        {
            printf("Arleady connected\n");
            continue;
        }
        id[i] = j;
        printf("%d %d\n", p, q);
    }
}
