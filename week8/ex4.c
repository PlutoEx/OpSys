#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main ()
{
	struct rusage usage;
	for (int i = 1; i <= 10; i ++)
	{
		int *a = malloc (1024 * 1024 * 10);
		memset (a, 0, 1024 * 1024 * 10);
		getrusage (RUSAGE_SELF, &usage);
		printf ("%d: %ld\n", i, usage.ru_maxrss);
		sleep (1);
	}
}
