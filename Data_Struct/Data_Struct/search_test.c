static int seqsearch(int *a, int len, int key) {//˳��ṹ�����㷨
	int i;
	for (i = len - 1; i >= 0; i--) {
		if (key == a[i]) {
			return i;//success
		}
	}
	return i;//err
}

static int binsearch(int *a, int len, int key) {//�۰���ң�ֻ��������������
	int low, high, mid;
	low = 0;
	high = len - 1;
	while (low <= high) {
		mid = (low + high) / 2;//ȡ�м�λ��
		if (key == a[mid]) {
			return mid;//success ���ҳɹ�
		}
		else if (key < a[mid])
		{
			high = mid - 1;//keyС���м�ֵ����high = mid -1
		}
		else
		{
			low = mid + 1;//key�����м�ֵ����low = mid + 1
		}
	}
	return -1;//err
}