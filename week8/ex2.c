#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	for (int i = 1; i <= 10; i ++)
	{
		int *a = malloc (1024 * 1024 * 10);
		memset (a, 0, 1024 * 1024 * 10);
		sleep (1);
	}
}