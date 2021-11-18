#include <stdio.h>

int res = 3, proc = 5;
int c[100][100], r[100][100];
int resNum[100], avRes[100];
int used[100];

int main ()
{
	FILE* input = fopen ("input_ok.txt", "r");
	FILE* output = fopen ("output.txt", "w");
	int cur;
	
	for (int i = 0; i < proc; i ++)
		used[i] = 0;
	for (int i = 0; i < res; i ++)
		fscanf (input, "%d", &resNum[i]);
	for (int i = 0; i < res; i ++)
		fscanf (input, "%d", &avRes[i]);
	for (int i = 0; i < proc; i ++)
		for (int j = 0; j < res; j ++)
			fscanf (input, "%d", &c[i][j]);
	for (int i = 0; i < proc; i ++)
		for (int j = 0; j < res; j ++)
			fscanf (input, "%d", &r[i][j]);

	int ok = 1;
	while (ok == 1)
	{
		ok = 0;
		for (int i = 0; i < proc; i ++)
		{
			int col = 0;
			for (int j = 0; j < res; j ++)
				if (r[i][j] < avRes[j])
					col ++;
			if (col == res && used[i] == 0)
				for (int p = 0; p < res; p ++)
					avRes[p] += c[i][p], ok = 1, used[i] = 1;
		}
	}
	int h = 1;
	for (int i = 0; i < proc; i++)
		if(used[i] == 0)
			fprintf(output, "There has occured availables deadlock in process %d \n", i), h = 0;
	if (h == 1)
		fprintf(output, "No deadlock detected");
}                                                                                              	