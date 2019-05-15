#pragma once
#ifndef  WW_TREE__H
#define  WW_TREE__H
#include "ww_type.h"

typedef struct ww_tree_node {
	data_t data;
	struct ww_tree_node* left;
	struct ww_tree_node* right;
}ww_tree_node_t;

ww_tree_node_t *ww_tree_new();
void ww_tree_delete(ww_tree_node_t *tr);


#endif // ! WW_TREE__H

