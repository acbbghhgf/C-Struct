#include "ww_stack.h"

ww_seqstack_t *ww_CreateStack(int len) {
	ww_seqstack_t *s = malloc(sizeof(ww_seqstack_t) + (len * sizeof(data_t)));
	s->maxlen = len;
	s->data = s + sizeof(ww_seqstack_t);
	s->top = 0;
	return s;
}

void ww_ClearStack(ww_seqstack_t * s)
{
	if (!s) {
		return;
	}
	free(s);
	s = NULL;
}

int ww_emptyStack(ww_seqstack_t * s)
{
	return s->top == 0 ? 1 : 0;
}

int ww_FullStack(ww_seqstack_t * s)
{
	return s->top == s->maxlen -1 ? 1: 0;
}

int ww_stack_push(ww_seqstack_t * s, data_t x)
{
	if (s->top == s->maxlen - 1) {
		printf("stack full\n");
		return -1;
	}
	s->data[s->top + 1] = x;
	s->top++;
	return 0;
}

data_t ww_stack_pop(ww_seqstack_t * s)
{
	if (s->top == 0) {
		return 0;
	}
	data_t x = s->data[s->top];
	s->top--;
	return x;
}

data_t ww_stack_gettop(ww_seqstack_t * s)
{
	if (s->top == 0) {
		return 0;
	}
	data_t x = *(s->data + s->top);
	return x;
}
