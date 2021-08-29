#include <stdio.h>

int main ()
{
	int n;
	char s[1000];
	scanf ("%s", &s);
	sscanf (s, "%d", &n);

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n - i; j ++)
			printf (" ");
		for (int j = 1; j < i * 2; j ++)
			printf ("*");
	 	printf ("\n");
	}
}