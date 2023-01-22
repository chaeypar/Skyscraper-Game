#include <stdlib.h>

void uparr(int** arr, char* temp, int* j)
{
	int i;

	i = 1;
	while (i <= 4)
	{
		arr[0][i] = temp[*j] - 48;
		i++;
		*j = *j + 2;
	}
 }

void downarr(int** arr, char* temp, int* j)
{
	int i;

	i = 1;
	while (i <= 4)
	{
		arr[5][i] = temp[*j] - 48;
		i++;
		*j = *j + 2;
	}
}

void leftarr(int** arr, char* temp, int* j)
{
	int i;

	i = 1;
	while (i <= 4)
	{
		arr[i][0] = temp[*j] - 48;
		i++;
		*j = *j + 2;
	}
}

void rightarr(int** arr, char* temp, int* j)
{
	int i;
	
	i = 1;
	while (i <= 4)
	{
		arr[i][5] = temp[*j] - 48;
		i++;
		*j = *j + 2;
	}
}

void arrmakeset(int** arr, char* temp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		arr[i] = (int*)malloc(sizeof(int) * 6);
		i++;
	}
	uparr(arr, temp, &j);
	downarr(arr, temp, &j);
	leftarr(arr, temp, &j);
	rightarr(arr, temp, &j);
}