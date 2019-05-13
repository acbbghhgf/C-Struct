#pragma once
#ifndef		WW_STCK__H
#define		WW_STCK__H

#include <stdio.h>
#include "ww_type.h"

//typedef int data_t; //栈中数据元素的数据类型
typedef struct ww_seqstack
{
	data_t *data;	//用指针指向栈的存储空间
	int maxlen;//当前栈的最大元素的个数
	int top;//指示栈顶位置的数组下标
}ww_seqstack_t;//顺序栈的类型定义

ww_seqstack_t *ww_CreateSeqStack(int len);
void ww_ClearSeqStack(ww_seqstack_t *s);
void ww_DeleteSeqStack(ww_seqstack_t *s);
int ww_emptySeqStack(ww_seqstack_t *s);
int ww_FullSeqStack(ww_seqstack_t *s);
int ww_Seqstack_push(ww_seqstack_t *s, data_t x);
data_t ww_Seqstack_pop(ww_seqstack_t *s);
data_t ww_Seqstack_gettop(ww_seqstack_t *s);


typedef struct node {
	data_t data;
	struct node *next;
}ww_linklist_t;

ww_linklist_t *ww_LinkStack_new();
int ww_LinkStack_empty(ww_linklist_t * l);
void ww_LinkStack_clear(ww_linklist_t *l);
void ww_LinkStack_delete(ww_linklist_t *l);
int ww_LinkStack_push(ww_linklist_t *l, data_t x);
data_t ww_LinkStack_pop(ww_linklist_t *l);
data_t ww_LinkStack_gettop(ww_linklist_t *l);



#endif
