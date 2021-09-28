#include<stdio.h>

int n, at[1000], bt[1000], wt[1000], tat[1000], ct[1000], temp, quantum, active[1000], att[1000], remain[1000];
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

int main()                 
{                                     
    printf ("Enter total number of processe: ");
    scanf ("%d", &n);

    printf ("Enter Process Arrival Times\n");
    for (int i = 1; i <= n; i ++)
    	scanf ("%d", &at[i]); 

    printf ("Enter Process Burst Times\n");
    for (int i = 1; i <= n; i ++)
    	scanf ("%d", &bt[i]);
 
    printf ("Enter Quantum: ");
    scanf ("%d", &quantum);


    for (int i = 1; i <= n; i ++)
    	for (int j = i + 1; j <= n; j ++)
    		if (at[i] > at[j])
    			swap (&at[i], &at[j]), swap (&bt[i], &bt[j]);

    for (int i = 1; i <= n; i ++)
    	active[i] = 1, remain[i] = bt[i];

    int done = 0;
	int cur = 1;
	while (done < n)
	{
		if (temp < at[cur])
			temp = at[cur];
		if (remain[cur] <= quantum)
		{
			temp += remain[cur];
			wt[cur] = temp - at[cur] - bt[cur];
			tat[cur] = bt[cur] + wt[cur];
			ct[cur] = at[cur] + tat[cur];
			done ++;
			active[cur] = 0;
		}
	   	else
	   	{
	   		temp += quantum;
	   		remain[cur] -= quantum;
	   		att[cur] = temp;
	   		active[cur] = 2;
	   	}

	   	int mn = 0;
	   	at[mn] = 1000;
	   	for (int i = 1; i <= n; i ++)
	   		if (active[i] == 1 && at[i] >= at[cur] && at[i] < at[mn])
	   			mn = i;
	   	for (int i = 1; i <= n; i ++)
	   		if (active[i] == 2 && att[i] >= at[cur] && att[i] < at[mn])
	   			mn = i;
	   	cur = mn;
	}

   	printf ("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    for (int i = 1; i <= n; i ++)
    	printf ("P%d:\t%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf ("\nAverage Waiting Time: %f\n", avwt / n);
    printf ("Average Turnaround Time: %f", avtat / n);
}