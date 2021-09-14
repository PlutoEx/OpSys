#include <stdio.h>
#include <sys/types.h>

int main ()
{
	int x;
	x = 3;
//	x = 5;
	for (int i = 1; i <= x; i ++)
	{
		fork ();
		printf ("Process: %d \n", getpid ());
		sleep (5);
	}
	
//	Console commands:  
//	gcc ex2.c -o ex2
//	./ex2 &
//	pstree        every 5 seconds


//	Results:   for x = 3
//	After 1 fork: init-openrc-+-login---bash-+-ex2---ex2
//	2 process                 |              `-pstree
//	                          `-login---bash

//	After 2 fork: init-openrc-+-login---bash-+-ex2-+-ex2---ex2
//	4 process                 |              |     `-ex2
//	                          |              `-pstree
//	                          `-login---bash

//	After 3 fork: init-openrc-+-login---bash-+-ex2-+-ex2-+-ex2---ex2
//	8 process                 |              |     |     `-ex2
//	                          |              |     |-ex2---ex2
//	                          |              |     `-ex2
//	                          |              `-pstree
//	                          `-login---bash

}
