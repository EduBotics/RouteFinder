#ifndef _NODE_H
#define _NODE_H

#include "link.h"

#define MAX_NODES 50

typedef struct _NODE NODE;
typedef enum _TYPE { BIDIR, UNIDIR } LINKTYPE;

NODE* get_node(char *node_name);
NODE* add_node(char *node_name);
void update_links(NODE* node, LINK* link);
void print_nodes();

#endif /* _NODE_H */