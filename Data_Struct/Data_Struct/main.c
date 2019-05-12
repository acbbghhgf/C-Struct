#include "ww_stack.h"

int main() {
	ww_seqstack_t *s;
	ww_linklist_t *l;
	int n = 10;
	s = ww_CreateSeqStack(n);
	l = ww_LinkStack_new();

	ww_Seqstack_push(s, 10);
	ww_Seqstack_push(s, 20);
	ww_Seqstack_push(s, 30);
	ww_Seqstack_push(s, 40);
	
	
	ww_LinkStack_push(l, 10);
	ww_LinkStack_push(l, 20);
	ww_LinkStack_push(l, 30);
	ww_LinkStack_push(l, 50);

	while (!ww_emptySeqStack(s)) {
		printf("==>%d\n", ww_Seqstack_pop(s));
	}
	printf("seqstack ======> over\n");
	
	while (!ww_LinkStack_empty(l)) {
		printf("==>%d\n", ww_LinkStack_pop(l));
	}
	printf("linkstack ======> over\n");

	getchar();
	return 0;
}