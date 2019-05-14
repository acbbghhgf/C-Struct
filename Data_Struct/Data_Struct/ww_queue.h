#pragma once
#ifndef WW_QUEUE__H
#define WW_QUEUE__H

#include "ww_type.h"


//À≥–Ú∂”¡–
typedef struct ww_sequeue {
	data_t *data;
	int max_len;
	int front;
	int rear;
}ww_sequeue_t;

ww_sequeue_t *ww_sequeue_new(int len);
void ww_sequeue_clear(ww_sequeue_t *seq);
void ww_sequeue_delete(ww_sequeue_t * seq);
int ww_sequeue_isfull(ww_sequeue_t * seq);
int ww_sequeue_isempty(ww_sequeue_t * seq);
int ww_sequeue_push(ww_sequeue_t * seq, data_t x);
int ww_sequeue_pop(ww_sequeue_t * seq, data_t * x);


typedef struct ww_linkqueue_node {
	data_t data;
	struct ww_linkqueue_node *next;
	struct ww_linkqueue_node *pre;
}ww_linkqueue_node_t;

typedef struct ww_linkqueue {
	int len;
	int max_len;
	ww_linkqueue_node_t *pop;
	ww_linkqueue_node_t *push;
}ww_linkqueue_t;

ww_linkqueue_t *ww_linkqueue_new(int len);
void ww_linkqueue_clear(ww_linkqueue_t *lq);
void ww_linkqueue_delete(ww_linkqueue_t *lq);
int ww_linkqueue_isfull(ww_linkqueue_t *lq);
int ww_linkqueue_isempty(ww_linkqueue_t *lq);
int ww_linkqueue_push(ww_linkqueue_t *lq, ww_linkqueue_node_t *node);
ww_linkqueue_node_t *ww_linkqueue_pop(ww_linkqueue_t *lq);




#endif // !WW_QUEUE__H
