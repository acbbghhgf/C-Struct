#include "ww_stack.h"

int main() {
	ww_seqstack_t *s;
	int n = 10;
	s = ww_CreateStack(n);
	
	ww_stack_push(s, 10);
	ww_stack_push(s, 10);
	ww_stack_push(s, 10);
	ww_stack_push(s, 10);

	while (!ww_emptyStack(s)) {
		printf("==>%d\n", ww_stack_pop(s));
	}
	printf("======> over\n");
	getchar();
	return 0;
}