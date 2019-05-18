#include "ww_stack.h"
#include "ww_queue.h"
#include "ww_sort.h"

#define N 8

int main(int argc, char **argv) {
	if (argc > 1) {
		ww_debug("param = [%s]\n", argv[1]);
	}
	int a[N] = { 50, 36, 66, 96, 75, 12, 25, 36};
	ww_debug("sort action:\n");
	ww_show_sort(a, N);
	//ww_seq_sort(a, N);
	//ww_shell_sort(a, N);
	ww_quick_sort(a, 0, N - 1);

	ww_debug("function is over\n");
	//getchar();
	ww_debug("list sort over:\n");
	ww_show_sort(a, N);
	system("pause");
	return 0;
}

