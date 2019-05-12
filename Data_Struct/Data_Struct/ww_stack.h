#pragma once
#ifndef		WW_STCK__H
#define		WW_STCK__H

#include <stdio.h>

typedef int data_t; //栈中数据元素的数据类型
typedef struct ww_seqstack
{
	data_t *data;	//用指针指向栈的存储空间
	int maxlen;//当前栈的最大元素的个数
	int top;//指示栈顶位置的数组下标
}ww_seqstack_t;//顺序栈的类型定义

ww_seqstack_t *ww_CreateStack(int len);
void ww_ClearStack(ww_seqstack_t *s);
int ww_emptyStack(ww_seqstack_t *s);
int ww_FullStack(ww_seqstack_t *s);

int ww_stack_push(ww_seqstack_t *s, data_t x);
data_t ww_stack_pop(ww_seqstack_t *s);
data_t ww_stack_gettop(ww_seqstack_t *s);


#endif
