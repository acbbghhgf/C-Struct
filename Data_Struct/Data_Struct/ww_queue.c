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

ww_linkqueue_t * ww_linkqueue_new(int len)
{
	ww_linkqueue_t *lq = (ww_linkqueue_t *)malloc(sizeof(*lq));
	if (lq == NULL) {
		ww_debug("link queue create fail\n");
		return NULL;
	}
	lq->max_len = len;
	lq->len = 0;
	lq->pop = 0;
	lq->push = 0;
	return lq;
}

void ww_linkqueue_clear(ww_linkqueue_t * lq)
{
}

void ww_linkqueue_delete(ww_linkqueue_t * lq)
{
	if (!lq) {
		ww_debug("lq is null\n");
		return;
	}
	ww_linkqueue_clear(lq);
	free(lq);
}

int ww_linkqueue_isfull(ww_linkqueue_t * lq)
{
	return lq->len == lq->max_len ? 1:0;
}

int ww_linkqueue_isempty(ww_linkqueue_t * lq)
{
	return lq->len == 0 ? 1 : 0;
}

int ww_linkqueue_push(ww_linkqueue_t * lq, ww_linkqueue_node_t *node)
{
	if (ww_linkqueue_isfull(lq)) {
		ww_debug("link queue is full\n");
		return -1;
	}
	node->pre = lq->push;
	if (lq->push) {
		lq->push->next = node;
	}
	node->next = 0;
	lq->push = node;
	if (!lq->pop) {
		lq->pop = node;
	}
	lq->len++;
	return 0;
}

ww_linkqueue_node_t * ww_linkqueue_pop(ww_linkqueue_t *lq)
{
	ww_linkqueue_node_t *n = NULL;
	if (lq->len <= 0) {
		return NULL;
	}
	if (!lq->pop) {
		return NULL;
	}
	n = lq->pop;
	lq->pop = lq->pop->next;
	if (lq->pop) {
		lq->pop->pre = 0;
	}
	else {
		lq->push = 0;
	}
	lq->len--;
	return n;
}
