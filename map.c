#include "find.h"
#include <stdlib.h>

void maptoarr(int **arr, int **map, int i, int j)
{
	int k;

	k = 0;
	while (k < 4)
	{
		arr[i][k + 1] = map[j][k];
		k++;
	}
}

void store_permutate(int* temp, int** map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[map[0][0]][i] = temp[i];
		i++;
	}
	map[0][0]++;
}

void permutate(int* temp, int* check, int n, int** map)
{
	int j;

	if (n == 4)
	{
		store_permutate(temp, map);
		return;
	}
	j = 1;
	while (j <= 4)
	{
		if (!check[j])
		{
			check[j] = 1;
			temp[n] = j;
			permutate(temp, check, n + 1, map);
			check[j] = 0;
		}
		j++;
	}
}

void mapmakeset(int** map)
{
	int i;
	int temp[4];
	int check[5];

	i = 0;
	while (i < 4)
	{
		temp[i] = 0;
		check[i] = 0;
		i++;
	}
	check[4] = 0;
	i = 0;
	while (i < 25)
	{
		map[i] = (int*)malloc(sizeof(int) * 6);
		i++;
	}
	map[0][0] = 1;
	permutate(temp, check, 0, map);
	find_left_right(map);
}
