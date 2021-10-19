#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double ratio;
int n, hit, miss, a;

struct page
{
    int id, cnt;
};

int main ()
{
    FILE* input = fopen ("input.txt", "r");
    printf ("Enter number of Pages: ");
    scanf ("%d", &n);
    
    struct page p[1111];

    for (int i = 1; i <= n; i ++)
        p[i].id = -1, p[i].cnt = 0;
    while (!feof (input))
    {
    	int ok = fscanf (input, "%d", &a);
    	if (ok == 1)
    	{
        	int ok2 = 0;
        	for (int i = 1; i <= n; i ++)
        	{
        	    p[i].cnt /= 2;    //  >> 1
        	    if (p[i].id == a)
        	    {
        	        ok2 = 1;
        	        hit ++;               
        	        p[i].cnt |= 30;    //   | 011110
        	    }
        	}
        	if (!ok2)
        	{
        		miss ++;
        		int j = 1;
        		for (int i = 2; i <= n; i ++)
        		{
        			if (p[i].id == -1) 
        			{
        				j = i;
        		    	break;
        		    }
        		    if (p[i].cnt < p[j].cnt)
        		    	j = i;
        		}
        		p[j].id = a;
        		p[j].cnt = 32768;   // 1000 0000 0000 0000
        	}
        }
    }
	ratio = (double) hit / (double) miss;
    printf ("Hit = %d\nMiss = %d\nRatio = %f", hit, miss, ratio);
}               