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



#endif // !WW_QUEUE__H
