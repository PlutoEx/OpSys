#include<stdio.h>

int n, at[1000], bt[1000], wt[1000], tat[1000], ct[1000], temp;
double avwt = 0, avtat = 0; 

int max (int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void swap (int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main()                    // NON  PRE - EMPITIVE ALGORITHM
{                                                       
    printf ("Enter total number of processe: ");
    scanf ("%d", &n);
 
    printf ("Enter Process Arrival Times\n");
    for (int i = 1; i <= n; i ++)
    	scanf ("%d", &at[i]); 

    printf ("Enter Process Burst Times\n");
    for (int i = 1; i <= n; i ++)
    	scanf ("%d", &bt[i]);
 
    for (int i = 1; i <= n; i ++)
    	for (int j = i + 1; j <= n; j ++)
    		if (at[i] > at[j] || (at[i] == at[j] && bt[i] > bt[j]))
    			swap (&at[i], &at[j]), swap (&bt[i], &bt[j]);

    for (int i = 1; i <= n; i ++)
    {                            
    	if (temp < at[i])
    		temp = at[i];
    	else
    	{
    		int k = i;
    		for (int j = i; j <= n; j ++)
    		{
    			if (at[j] > temp + bt[i])                                    
    				break;
    		   	if (max (temp, at[k]) + bt[k] > max (at[j], temp) + bt[j])
    		   		k = j;
    		}
    		swap (&at[i], &at[k]);
    		swap (&bt[i], &bt[k]);
    		if (temp < at[i])
    			temp = at[i];
    	}
    	temp += bt[i];
    	ct[i] = temp;
    	tat[i] = ct[i] - at[i];
    	if (tat[i] < 0)
    		tat[i] = 0;
    	wt[i] = tat[i] - bt[i];
    	if (wt[i] < 0)
    		wt[i] = 0;
    	avwt += wt[i];
    	avtat += tat[i];
    }                                               

   	printf ("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    for (int i = 1; i <= n; i ++)
    	printf ("P%d:\t%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf ("\nAverage Waiting Time: %f\n", avwt / n);
    printf ("Average Turnaround Time: %f", avtat / n);
}