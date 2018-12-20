/*****************/
/* Node Link API */
/*****************/
#include <stdlib.h>
#include <stdint.h>
#include "link.h"
#include "node.h"

struct _LINK {
	struct _NODE* from;
	struct _NODE* to;
	uint8_t distance;
};

LINK links[MAX_LINKS];
uint8_t LINK_INDEX = 0;

/* Find an existing link matching `source` and `dest`, or return NULL */
LINK *find_link(NODE* source, NODE* dest) {
	LINK *the_link = NULL;
	for (uint8_t idx = 0; idx < LINK_INDEX; idx++) {
		the_link = &links[idx];
		if (the_link->from == source && the_link->to == dest) {
			break;
		}
	}
	return the_link;
}

/* Get the next available link from the array (or malloc if allowed) */
LINK *get_link() {
	LINK *the_link = NULL;
	if (LINK_INDEX < MAX_LINKS) {
		the_link = &links[LINK_INDEX++];
		the_link->from = NULL;
		the_link->to = NULL;
		the_link->distance = 0;
	}
	return the_link;
}

/* Create and return the link with `source`, `dest` and `dist` (LINK constructor) */
LINK *add_link(NODE* source, NODE* dest, uint8_t dist) {
	LINK *the_link = find_link(source, dest);
	if (the_link == NULL) {
		the_link = get_link();
		the_link->from = source;
		the_link->to = dest;
	}
	the_link->distance = dist; /* Overwrite */
	return the_link;
}
