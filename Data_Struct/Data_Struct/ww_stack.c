#include "ww_stack.h"

ww_seqstack_t *ww_CreateSeqStack(int len) {
	ww_seqstack_t *s = malloc(sizeof(ww_seqstack_t) + (len * sizeof(data_t)));
	s->maxlen = len;
	s->data = s + sizeof(ww_seqstack_t);
	s->top = 0;
	return s;
}

void ww_ClearSeqStack(ww_seqstack_t * s)
{
	s->top = 0;
	s->data[s->top] = 0;
}

void ww_DeleteSeqStack(ww_seqstack_t * s)
{
	if (!s) {
		return;
	}
	free(s);
	s = NULL;
}

int ww_emptySeqStack(ww_seqstack_t * s)
{
	return s->top == 0 ? 1 : 0;
}

int ww_FullSeqStack(ww_seqstack_t * s)
{
	return s->top == s->maxlen -1 ? 1: 0;
}

int ww_Seqstack_push(ww_seqstack_t * s, data_t x)
{
	if (s->top == s->maxlen - 1) {
		printf("stack full\n");
		return -1;
	}
	s->data[s->top + 1] = x;
	s->top++;
	return 0;
}

data_t ww_Seqstack_pop(ww_seqstack_t * s)
{
	if (s->top == 0) {
		return 0;
	}
	data_t x = s->data[s->top];
	s->top--;
	return x;
}

data_t ww_Seqstack_gettop(ww_seqstack_t * s)
{
	if (s->top == 0) {
		return 0;
	}
	data_t x = *(s->data + s->top);
	return x;
}

ww_linklist_t * ww_LinkStack_new()
{
	ww_linklist_t *l;
	l = malloc(sizeof(*l));
	l->next = NULL;
	return l;
}

int ww_LinkStack_empty(ww_linklist_t * l)
{
	return l->next == NULL ? 1: 0;
}

void ww_LinkStack_clear(ww_linklist_t * l)
{
	ww_linklist_t *p;
	while(l->next){
		p = l->next;
		l->next = p->next;
		p->data = 0;
		free(p);
	}
}

void ww_LinkStack_delete(ww_linklist_t * l)
{
	ww_linklist_t *p;
	while (l->next) {
		p = l->next;
		l->next = p->next;
		p->data = 0;
		free(p);
	}
	l->data = 0;
	free(l);
	l = NULL;
}

int ww_LinkStack_push(ww_linklist_t * l, data_t x)
{
	ww_linklist_t *p = malloc(sizeof(*p));
	p->data = x;
	p->next = l->next;
	l->next = p;
	return 0;
}

data_t ww_LinkStack_pop(ww_linklist_t * l)
{
	ww_linklist_t *p;
	if (!l->next) {
		return 0;
	}
	p = l->next;
	if (!p->next) {
		l->next = NULL;
	}
	else {
		l->next = p->next;
	}
	data_t x = p->data;
	free(p);
	return x;
}

data_t ww_LinkStack_gettop(ww_linklist_t * l)
{
	return l->next->data;
}
