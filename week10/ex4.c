#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int cnt;
struct dirent *dp;	
struct stat st;

int main ()
{
	DIR *dir = opendir ("tmp/");    
    
    printf("File\tHard Links\n");
    while ((dp = readdir (dir)) != NULL)
    {
    	char path[1001] = "tmp/";
        DIR *dir_i = opendir (path);
        strcat (path, dp->d_name);
        stat (path, &st);

        struct dirent *dp_i;
        struct stat st_i;

        cnt = 0;
        char *names[1001];
        while ((dp_i = readdir (dir_i)) != NULL)
        {
        	char path_i[256] = "tmp/";
            strcat (path_i, dp_i->d_name);
            stat (path_i, &st_i);
            if (st.st_ino == st_i.st_ino)
            {
                names[cnt] = dp_i->d_name;
                cnt ++;
            }
        }

        closedir (dir_i);
        if (cnt >= 2)
        {
        	printf ("%s\t", dp->d_name);
        	for (int i = 0; i < cnt; i ++)
       			printf("%s ", names[i]);
       		printf ("\n");
       	}
    }
    closedir (dir);
}