static int seqsearch(int *a, int len, int key) {//顺序结构查找算法
	int i;
	for (i = len - 1; i >= 0; i--) {
		if (key == a[i]) {
			return i;//success
		}
	}
	return i;//err
}

static int binsearch(int *a, int len, int key) {//折半查找，只能用于有序表查找
	int low, high, mid;
	low = 0;
	high = len - 1;
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