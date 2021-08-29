#include <stdio.h>

void swap (int *, int *);

int main ()
{
	int a, b;
	printf ("a = ");
	scanf ("%d", &a);
	printf ("b = ");
	scanf ("%d", &b);

	swap (&a, &b);
	printf ("a = %d\nb = %d", a, b);
}

void swap (int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}