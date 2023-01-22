#ifndef _CHECK_H_
#define _CHECK_H_

int check_left(int** arr, int* check, int col, int* cnt);
int check_right(int** arr, int* check, int col, int* cnt);
int check_assist(int** arr, int* check, int col);
int col_check(int** arr, int col);
int full_col_check(int** arr);

#endif