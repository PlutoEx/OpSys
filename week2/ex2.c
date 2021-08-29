#include <stdio.h>
#include <string.h>

int main ()
{
	char s[1000];
	printf ("Enter text: ");
	fgets (s, 1000, stdin);


	printf ("Reverse: ");
	for (int i = strlen (s); i >= 0; i --)
		printf ("%c", s[i]);
}