#ifndef _LL_H
#define _LL_H

#include <stdlib.h>
#include <stdint.h>
#include "ll.h"

/* Linked List API */
struct _LL {
	void *item;
	struct _LL *next;
};

LL ll_entries[MAX_LL];
uint8_t LL_INDEX = 0;

LL *ll_find_item(void *item) {
	for (uint8_t idx = 0; idx < LL_INDEX; idx++) {
		if (ll_entries[idx].item == item) {
			return &ll_entries[idx];
		}
	}
	return NULL;
}

LL *ll_add_item(void *item) {
	LL *the_item;
	if ((the_item = ll_find_item(item)) != NULL) {
		return the_item;
	}
	return &ll_entries[LL_INDEX++];
}

void ll_link_item(void *item, void *next) {
	LL *the_item = ll_add_item(item);
	LL *next_item = ll_add_item(next);
	the_item->next = next_item;
}

#endif /* _LL_H */