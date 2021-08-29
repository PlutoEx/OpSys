#include <stdio.h>

int n;

void fun1 ()
{
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n - i; j ++)
			printf (" ");
		for (int j = 1; j < i * 2; j ++)
			printf ("*");
	 	printf ("\n");
	}
}

void fun2 ()
{
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= i; j ++)
			printf ("*");
	 	printf ("\n");
	}
}

void fun3 ()
{
	for (int i = 1; i <= n; i ++)
	{
		if (i <= n / 2)
			for (int j = 1; j <= i; j ++)
				printf ("*");
		else
			for (int j = 1; j <= n - i + 1; j ++)
				printf ("*");
	 	printf ("\n");
	}
}


void fun4 ()
{
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
			printf ("*");
	 	printf ("\n");
	}
}


int main ()
{
	int x;
	char s[1000];
	printf ("Enter number: ");
	scanf ("%s", &s);
	sscanf (s, "%d", &n);

	printf ("Enter type (1-4): ");
	scanf ("%d", &x);
	if (x == 1)
		fun1 ();
	else if (x == 2)
		fun2 ();
   	else if (x == 3)
    	fun3 ();
    else if (x == 4)
    	fun4 ();
}