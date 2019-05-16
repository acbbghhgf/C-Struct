#include "ww_stack.h"
#include "ww_queue.h"

#define N 10
int binsearch(int *a, int key);
int main() {
	int a[N] = { 3, 5, 6, 7, 8, 9, 12, 13, 17, 19 };
	int i, key;
	while (1)
	{
		ww_debug("pls input key:\n");
		scanf_s("%d", &key);
		if (key == -1) {
			ww_debug("退出程序\n");
			break;
		}
		i = binsearch(a, key);
		if (i == -1) {
			ww_debug(" search error\n");
		}
		else {
			ww_debug("search %d at %d\n", key, i);
		}
	}
	ww_debug("function is over\n");
	//getchar();
	system("pause");
	return 0;
}

int binsearch(int *a, int key) {//折半查找，只能用于有序表查找
	int low, high, mid;
	low = 0;
	high = N - 1;
	while (low <= high) {
		mid = (low + high) / 2;//取中间位置
		if (key == a[mid]) {
			return mid;//success 查找成功
		}
		else if (key < a[mid])
		{
			high = mid - 1;//key小于中间值，则high = mid -1
		}
		else
		{
			low = mid + 1;//key大于中间值，则low = mid + 1
		}
	}
	return -1;//err
}