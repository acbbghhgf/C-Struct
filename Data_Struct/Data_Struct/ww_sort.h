#pragma once
#ifndef WW_SORT__H
#define WW_SORT__H
#include "ww_type.h"

void ww_show_sort(int * a, int n);
void ww_seq_sort(int * a, int n);

void ww_shell_sort(int * a, int n);

int ww_quick_pass(int * a, int i, int j);

void ww_quick_sort(int * a, int low, int high);



#endif // !WW_SORT__H