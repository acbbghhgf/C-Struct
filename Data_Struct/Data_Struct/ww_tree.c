#include "ww_tree.h"

ww_tree_node_t * ww_tree_new()
{
	ww_tree_node_t *tr = (ww_tree_node_t *)malloc(sizeof(ww_tree_node_t));
	if (!tr) {
		ww_debug("create fail\n");
		return NULL;
	}
	return tr;
}

void ww_tree_delete(ww_tree_node_t * tr)
{
	if (tr) {
		free(tr);
	}
}
