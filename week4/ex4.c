#include <stdio.h>
#include <stdlib.h>

int main ()
{
	
	char command[10001];

	printf ("Welcome to Terminal Simulator\n");
	printf ("Write a command\n");
	printf ("Press 0 to Exit\n");
	
	while (1)
	{
		printf (">: ");
		fgets (command, 10001, stdin);
		if (command[0] == '0')
			return 0;
		system (command);
	}
}
