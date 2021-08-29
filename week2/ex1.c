#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main ()
{
	printf ("Size of int: %d\n", sizeof (int));
	printf ("Size of double: %d\n", sizeof (double));
	printf ("Size of float: %d\n\n", sizeof (float));

	printf ("Max value of int: %d\n", INT_MAX);
	printf ("Max value of double: %e\n", DBL_MAX);
	printf ("Max value of float: %e\n", FLT_MAX);
}