#include "ww_stack.h"
#include "ww_queue.h"
#include "ww_sort.h"
#include <time.h>

#define N 8

int main(int argc, char **argv) {
	FILE *fps, *fpd;
	char buf[N];
	int n;
	//if (argc < 3) {
	//	ww_debug("usage :%s <src_file> <dst file>\n", argv[0]);
	//	return -1;
	//}
	char file_name[] = "111.txt";
	char file_name_2[] = "222.txt";
	fopen_s(&fps, file_name, "r");
	if ( fps== NULL) {
		perror("fopen src file error\n");
		return -1;
	}
	fopen_s(&fpd, file_name_2, "w");
	if ( fpd == NULL) {
		perror("fopen dst file error\n");
		return -1;
	}
	time_t t;
	struct tm tp_1;
	struct tm *tp = &tp_1;
	time(&t);
	localtime_s(tp, &t);
	
	char tmp[128] = { 0 };
	
	while (n = fread(buf, N, 1, fps) > 0)
	{
		fwrite(buf, N, n, fpd);
	}
	n = sprintf_s(tmp, sizeof(tmp), "\n\rtime is  %d-%02d-%02d %02d:%02d:%02d\n", tp->tm_year +1900, tp->tm_mon+1, \
	tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);
	fwrite(buf, n, 1, fpd);

	fclose(fps);
	fclose(fpd);
	ww_debug("function over!\n");
	system("pause");
	return 0;
}

