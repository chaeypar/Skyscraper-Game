#include "map.h"

void find_comb(int** arr, int** map, int i, int* flag)
{
	int find1;
	int find2;
	int j;

	if (*flag)
		return;
	else if (i == 5)
	{
		checky(arr, flag);
		return;
	}
	find1 = arr[i][0];
	find2 = arr[i][5];
	j = 1;
	while (j < 25)
	{
		if (map[j][4] == find1 && map[j][5] == find2)
		{
			maptoarr(arr, map, i, j);
			find_comb(arr, map, i + 1, flag);
		}
		j++;
	}
}

void find_left(int**map, int i)
{
	int cnt;
	int prev;
	int j;

	cnt = 1;
	prev = map[i][0];
	j = 1;
	while (j <= 3)
	{
		if (map[i][j] > prev)
		{
			prev = map[i][j];
			cnt++;
		}
		j++;
	}
	map[i][4] = cnt;
}

void find_right(int** map, int i)
{
	int cnt;
	int prev;
	int j;

	cnt = 1;
	prev = map[i][3];
	j = 2;
	while (j >= 0)
	{
		if (map[i][j] > prev)
		{
			prev = map[i][j];
			cnt++;
		}
		j--;
	}
	map[i][5] = cnt;
}

void find_left_right(int** map)
{
	int i;

	i = 1;
	while (i < 25)
	{
		find_left(map, i);
		find_right(map, i);
		i++;
	}
}
