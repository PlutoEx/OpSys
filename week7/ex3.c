#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, m;

int main ()
{
    srand (time (NULL));
    printf ("Enter First array size: ");
    scanf ("%d", &n);

    int* a = malloc (n * sizeof (int));
    for (int i = 0; i < n; i ++)
    {
        *(a + i) = i;
        printf ("%d ", *(a + i));
    }

    printf ("\nEnter Second array size: ");
    scanf ("%d", &m);

    a = realloc (a, m * sizeof (int));

    if (n < m)
        for (int i = n; i < m; i++)
            *(a + i) = 0;

    for (int i = 0; i < m; i ++)
        printf ("%d ", *(a + i));
}