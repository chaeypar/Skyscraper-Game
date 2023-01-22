#include <stdlib.h>
#include <unistd.h>
#include "check.h"
#include "setting.h"
#include "find.h"
#include "valid.h"
#include "print.h"
#include "map.h"

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