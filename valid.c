#include "print.h"
#include "check.h"

void checky(int** arr, int* flag)
{
	if (full_col_check(arr))
	{
		ft_print(arr);
		*flag = 1;
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
			return 0;
		i++;
	}
	if (cnt == 16)
		return 1;
	return 0;
}