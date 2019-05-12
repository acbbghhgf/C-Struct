#pragma once
#ifndef		WW_STCK__H
#define		WW_STCK__H

#include <stdio.h>

typedef int data_t; //ջ������Ԫ�ص���������
typedef struct ww_seqstack
{
	data_t *data;	//��ָ��ָ��ջ�Ĵ洢�ռ�
	int maxlen;//��ǰջ�����Ԫ�صĸ���
	int top;//ָʾջ��λ�õ������±�
}ww_seqstack_t;//˳��ջ�����Ͷ���

ww_seqstack_t *ww_CreateStack(int len);
void ww_ClearStack(ww_seqstack_t *s);
int ww_emptyStack(ww_seqstack_t *s);
int ww_FullStack(ww_seqstack_t *s);

int ww_stack_push(ww_seqstack_t *s, data_t x);
data_t ww_stack_pop(ww_seqstack_t *s);
data_t ww_stack_gettop(ww_seqstack_t *s);


#endif
