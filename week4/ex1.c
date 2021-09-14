#include <stdio.h>
#include <sys/types.h>

int main ()
{
	int n = 47;
	int pid = fork ();
	if (pid != 0)
		printf ("Hello from parent [%d - %d]\n",pid, n);
	else
		printf ("Hello from child [%d - %d]\n", pid , n);
}
