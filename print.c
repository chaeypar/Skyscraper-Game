#include <unistd.h>

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
