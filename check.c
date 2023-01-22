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
	return 1;
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
	return 1;
}

int check_assist(int** arr, int *check, int col)
{
	int cnt;
	int tp;
	
	tp = arr[0][col];
	cnt = 1;
	if (!check_left(arr, check, col, &cnt))
		return 0;
	if (tp != cnt)
		return 0;
	tp = arr[5][col];
	cnt = 1;
	if (!check_right(arr, check, col, &cnt))
		return 0;
	if (tp != cnt)
		return 0;
	return 1;
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
	return check_assist(arr,check,col);
}

int full_col_check(int** arr)
{
	int i;
	i = 1;
	while (i <= 4)
	{
		if (!col_check(arr, i))
		{
			return 0;
		}
		i++;
	}
	return 1;
}
