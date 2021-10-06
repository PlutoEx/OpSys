#include <stdio.h>
#include <malloc.h>

int n;

int main () 
{
    printf ("Enter size: ");
    scanf ("%d", &n);
    int *a = malloc (n * sizeof( int));
    for (int i = 0; i < n; i ++)
        a[i] = i;
    for (int i = 0; i < n; i ++)
    	printf ("%d ", i);
    free (a);
}