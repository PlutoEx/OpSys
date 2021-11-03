#include <stdio.h>
#include <dirent.h>

DIR *d;
struct dirent *dir;

int main ()
{
	d = opendir ("/");               
    while ((dir = readdir (d)) != NULL)
    	printf ("%s\n", dir -> d_name);
    closedir (d);
}   	