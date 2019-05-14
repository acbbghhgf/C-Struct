#include "ww_stack.h"
#include "ww_queue.h"

int main() {
	ww_debug("action!\n");
	ww_linkqueue_t *q = ww_linkqueue_new(10);
	ww_linkqueue_node_t *node1 = (ww_linkqueue_node_t *)malloc(sizeof(*node1));
	ww_linkqueue_node_t *node2 = (ww_linkqueue_node_t *)malloc(sizeof(*node2));
	ww_linkqueue_node_t *node3 = (ww_linkqueue_node_t *)malloc(sizeof(*node3));
	ww_linkqueue_node_t *node4 = (ww_linkqueue_node_t *)malloc(sizeof(*node4));

	node1->data = 3;
	node2->data = 8;
	node3->data = 12;
	node4->data = 14;

	ww_linkqueue_push(q, node1);
	ww_linkqueue_push(q, node2);
	ww_linkqueue_push(q, node3);
	ww_linkqueue_push(q, node4);
	
	ww_linkqueue_node_t *new_node;
	while(1) {
		new_node = ww_linkqueue_pop(q);
		if (!new_node) {
			ww_debug("new_node is null\n");
			break;
		}
		ww_debug("new_node = %d\n", new_node->data);
	}
	ww_debug("function is over\n");
	getchar();
	return 0;
}