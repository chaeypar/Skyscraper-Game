#include<stdlib.h>
#include<unistd.h>

int check_left(int** arr, int* check, int col, int* cnt);
int check_right(int** arr, int* check, int col, int* cnt);
int check_assist(int** arr, int* check, int col);
int col_check(int** arr, int col);
int full_col_check(int** arr);
void ft_putchar(char c);
void ft_print(int** arr);
void maptoarr(int** arr, int** map, int i, int j);
void checky(int** arr, int* flag);
void find_comb(int** arr, int** map, int i, int* flag);
void find_left(int** map, int i);
void find_right(int** map, int i);
void find_left_right(int** map);
int is_valid(char* temp);
void uparr(int** arr, char* temp, int* j);
void downarr(int** arr, char* temp, int* j);
void leftarr(int** arr, char* temp, int* j);
void rightarr(int** arr, char* temp, int* j);
void arrmakeset(int** arr, char* temp);
void store_permutate(int* temp, int** map);
void permutate(int* temp, int* check, int n, int** map);
void mapmakeset(int** map);

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

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print(int** arr)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			ft_putchar(arr[i][j] + 48);
			if (j != 4)
			{
				ft_putchar(' ');
			}
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

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

void checky(int** arr, int* flag)
{
	if (full_col_check(arr))
	{
		ft_print(arr);
		*flag = 1;
	}
}

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

int is_valid(char* temp)
{
	int i;
	int cnt;

	cnt = 0;
	i = 0;
	while (temp[i] != 0)
	{
		if (temp[i] >= '1' && temp[i] <= '9')
			cnt++;
		else if (temp[i] != ' ')
			return (0);
		i++;
	}
	if (cnt == 16)
		return (1);
	return (0);
}

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

int check_left(int** arr, int *check, int col, int *cnt)
{
	int i;
	int prev;

	prev = arr[1][col];
	i = 2;
	check[prev] = 1;
	while (i <= 4)
	{
		if (check[arr[i][col]])
			return 0;
		else
			check[arr[i][col]] = 1;
		if (arr[i][col] > prev)
		{
			prev = arr[i][col];
			*cnt = *cnt + 1;
		}
		i++;
	}
	return (1);
}

int check_right(int** arr, int* check, int col, int* cnt)
{
	int i;
	int prev;

	prev = arr[4][col];
	i = 3;
	check[prev] = 0;
	while (i >= 1)
	{
		if (!check[arr[i][col]])
			return 0;
		else
			check[arr[i][col]] = 0;
		if (arr[i][col] > prev)
		{
			prev = arr[i][col];
			*cnt = *cnt + 1;
		}
		i--;
	}
	return (1);
}

int check_assist(int** arr, int *check, int col)
{
	int cnt;
	int tp;
	
	tp = arr[0][col];
	cnt = 1;
	if (!check_left(arr, check, col, &cnt))
		return (0);
	if (tp != cnt)
		return (0);
	tp = arr[5][col];
	cnt = 1;
	if (!check_right(arr, check, col, &cnt))
		return (0);
	if (tp != cnt)
		return (0);
	return (1);
}

int col_check(int** arr, int col)
{
	int check[5];
	int i;

	i = 1;
	while (i <= 4)
	{
		check[i] = 0;
		i++;
	}
	return (check_assist(arr,check,col));
}

int full_col_check(int** arr)
{
	int i;
	i = 1;
	while (i <= 4)
	{
		if (!col_check(arr, i))
		{
			return (0);
		}
		i++;
	}
	return (1);
}



int main(int argc, char* argv[])
{
	argc +=1;
	int** map;
	int** arr;
	int flag;
	int i;
	if (!is_valid(argv[1]))
		return (0);
	map = (int**)malloc(sizeof(int*) * 25);
	arr = (int**)malloc(sizeof(int*) * 6);
	flag = 0;
	mapmakeset(map);
	arrmakeset(arr, argv[1]);
	find_comb(arr, map, 1, &flag);
	i = 0;
	while (i < 6)
		free(arr[i++]);
	i = 0;
	while (i < 25)
		free(map[i++]);
	free(arr);
	free(map);
	return (0);
}