#include "ww_stack.h"
#include "ww_queue.h"

int main() {
	ww_debug("action!\n");

	ww_sequeue_t *seq = ww_sequeue_new(10);
	ww_sequeue_push(seq, 2);
	ww_sequeue_push(seq, 12);
	ww_sequeue_push(seq, 4);
	ww_sequeue_push(seq, 15);
	ww_sequeue_push(seq, 32);
	ww_sequeue_push(seq, 11);

	int i = 0;
	data_t x = 0;
	while (0 == ww_sequeue_pop(seq, &x))
	{
		ww_debug("==> x = [%d]\n", x);
	}
	ww_debug("seq is empty\n");
	ww_sequeue_clear(seq);
	
	ww_sequeue_push(seq, 11);
	ww_sequeue_push(seq, 32);
	ww_sequeue_push(seq, 15);
	ww_sequeue_push(seq, 4);
	while (0 == ww_sequeue_pop(seq, &x))
	{
		ww_debug("[xx]==> x = [%d]\n", x);
	}
	ww_debug("seq is empty scond\n");

	ww_sequeue_delete(seq);

	getchar();
	return 0;
}