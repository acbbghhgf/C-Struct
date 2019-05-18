#include "ww_sort.h"

void ww_show_sort(int *a, int n) {
	int i;
	ww_debug("show list\n");
	for (i = 0; i < n; i++) {
		//ww_debug("%d\t", a[i]);
		printf("%d\t", a[i]);
	}
	printf("\n");
	ww_debug("show over\n");
}

void ww_seq_sort(int *a, int n) {//插入排序
	int i = 0;
	int j, temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (temp < a[j]) {
				a[j + 1] = a[j];
			}
			else {
				break;
			}
		}
		a[j + 1] = temp;
		ww_show_sort(a, n);
	}
}

void ww_shell_sort(int *a, int n) {//块状插入排序
	int i, j, temp;
	int d;
	for (d = n / 2; d > 0; d /=2)
	{
		for (i = d; i < n; i++)
		{
			temp = a[i];
			for (j = i - d; j >= 0; j -= d) {
				if (temp < a[j]) {
					a[j + d] = a[j];
				}
				else
				{
					break;
				}
			}
			a[j + d] = temp;
		}
		ww_show_sort(a, n);
	}
}

int ww_quick_pass(int *a, int i, int j) {
	int tmp;
	tmp = a[i];//a[i]作为基准保存
	while (i < j)
	{
		while (i < j && tmp <= a[j])//上界比较
		{
			j--;
		}
		if (i < j) {//交换
			a[i] = a[j];
		}
		while (i < j && tmp >= a[i])//下届比较
		{
			i++;
		}
		if (i < j) {//交换
			a[j] = a[i];
		}
	}//找到基准位置，进行存放。
	a[i] = tmp;
	return i;//返回基准下标
}

void ww_quick_sort(int *a, int low, int high) {//快速排序
	int mid;
	if (low < high) {
		mid = ww_quick_pass(a, low, high);
		ww_quick_sort(a, low, mid - 1);
		ww_quick_sort(a, mid+1, high);
	}
}