#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int n, m;

void *realloc2 (void *ptr)
{
    void *newPtr;
    newPtr = malloc (m * sizeof (int));
    size_t initialSize = malloc_usable_size (ptr);
    if (ptr != NULL)
    {
        if (initialSize < m * sizeof (int))
            memcpy (newPtr, ptr, initialSize);
        else
            memcpy (newPtr, ptr, m * sizeof (int));
        free (ptr);
    }
    return newPtr;
}

int main ()
{
	printf ("Enter Array Size: ");
	scanf ("%d", &n);
	printf ("Enter New Array Size: ");
	scanf ("%d", &m);

    int *a = malloc (n * sizeof (int));
    for (int i = 0; i < n; i ++)
        *(a + i) = i;
    for (int i = 0; i < n; i ++)
        printf ("%d ", *(a + i));

    printf ("\n");
    a = realloc2 (a);
    for (int i = 0; i < m; i ++)
        printf ("%d ", *(a + i));
}