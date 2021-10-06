#include <stdio.h>              

int main ()
{
    char **s1;
    char *s2 = "Hello World!";
    s1 = &s2;
    printf ("s1 = '%s'\n", *s1);
    s1[0] = s2;
    printf ("s1[0] = '%s'", s1[0]);
}                                