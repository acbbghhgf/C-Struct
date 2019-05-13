#include "ww_queue.h"

ww_sequeue_t * ww_sequeue_new(int len)
{
	ww_sequeue_t *seq = (ww_sequeue_t *)malloc(sizeof(ww_sequeue_t) + sizeof(data_t) * len);
	seq->max_len = len;
	seq->data = seq + sizeof(ww_sequeue_t);
	seq->rear = 0;
	seq->front = 0;
	return seq;
}

void ww_sequeue_clear(ww_sequeue_t * seq)
{
	seq->front = 0;
	seq->rear = 0;
}

void ww_sequeue_delete(ww_sequeue_t *seq) {
	free(seq);
}

int ww_sequeue_isfull(ww_sequeue_t *seq) {
	return seq->rear == seq->max_len - 1 ? 1 : 0;
}

int ww_sequeue_isempty(ww_sequeue_t *seq) {
	return seq->rear == seq->front ? 1 : 0;
}

int ww_sequeue_push(ww_sequeue_t *seq, data_t x) {
	if (ww_sequeue_isfull(seq)) {
		ww_debug("sequeue is full\n");
		return -1;
	}
	seq->data[seq->rear] = x;
	++seq->rear;
	return 0;
}

int ww_sequeue_pop(ww_sequeue_t *seq, data_t *x) {
	if (ww_sequeue_isempty(seq)) {
		ww_debug("sequeue is empty\n");
		return -1;
	}
	*x = seq->data[seq->front];
	++seq->front;
	return 0;
}