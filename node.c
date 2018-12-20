/************/
/* Node API */
/************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "link.h"
#include "node.h"


struct _NODE {
	char* name;
	struct _LINK* links;
};


NODE nodes[MAX_NODES];
uint8_t NODE_INDEX = 0;

/* Find and return node with `node_name`. Returns NULL if not found. */
NODE* get_node(char *node_name) {
	for (uint8_t idx = 0; idx < NODE_INDEX; idx++) {
		if (nodes[idx].name == node_name) {
			return &nodes[idx];
		}
	}
	return NULL;
}

/* Create node with `node_name` (NODE constructor) */
NODE* add_node(char *node_name) {
	NODE *the_node = get_node(node_name);
	if (the_node == NULL) {
		the_node = &nodes[NODE_INDEX++];
		the_node->name = node_name;
	}
	return the_node;
}

/* Add `link` to `node`'s `links` or create the first in the chain */
void update_links(NODE* node, LINK* link) {
	LINK* links = node->links;
	if (links == NULL) {
		links = node->links;
	}
}

/* Print all the nodes in `nodes` */
void print_nodes() {
	for (uint8_t idx = 0; idx < NODE_INDEX; idx++) {
		printf("NODE %s\n", nodes[idx].name);
	}
}
