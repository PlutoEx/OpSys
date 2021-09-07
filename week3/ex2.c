#include <stdio.h>

void swap (int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void bubble_sort (int a[], int n)
{
	for (int i = 1; i < n; i ++)
		for (int j = i + 1; j <= n; j ++)
			if (a[i] > a[j])
				swap (&a[i], &a[j]);
}

void print_array (int a[], int n)
{
	for (int i = 1; i <= n; i ++)
		printf ("%d ", a[i]);
}

int main ()
{
	int n, a[100];
	printf ("Enter number of array: ");
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf ("%d", &a[i]);
	bubble_sort (a, n);
	print_array (a, n);	
}