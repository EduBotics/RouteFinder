#ifndef _LINK_H
#define _LINK_H

#include <stdint.h>

typedef struct _LINK LINK;

#include "node.h"

#define MAX_LINKS 200


LINK *find_link(NODE* source, NODE* dest);
LINK *get_link();
LINK *add_link(NODE* source, NODE* dest, uint8_t dist);

#endif /* _LINK_H */