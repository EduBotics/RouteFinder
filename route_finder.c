#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "link.h"
#include "node.h"


int main(void) {
	uint8_t found;
	NODE *source_node, *dest_node;
	FILE *routes = fopen("routes.dat", "r");

	while(!feof(routes)) {
		LINKTYPE type = BIDIR;
		LINK* link1, *link2;
		char source[20], dest[20], dir[3] = "\0";
		uint8_t dist;

		//found = fscanf(routes, "\"%[a-zA-Z ]\" %3[-<>] \"%[a-zA-Z ]\" : %d", source, dir, dest, (int*)&dist);
		fscanf(routes, "\"%[^\"]\"", source);
		fscanf(routes, " %3s ", dir);
		/*
		fscanf(routes, "\"%[a-zA-Z ]\"", dest);
		fscanf(routes, " : ");
		fscanf(routes, "%d\n", (int*)&dist);
		*/
		if (ferror(routes)) {
			exit(1);
		}
		if (strlen(dir) != 3) {
			type = UNIDIR;
		}

		printf("Found: \"%s\" \"%s\" \"%s\" \"%d\"\n", source, dir, dest, dist);
		printf("%s %s %s : %d\n", source, (type == BIDIR ? "<->" : "->"), dest, dist);

		exit(0);

		source_node = add_node(&source[0]);
		dest_node = add_node(&dest[0]);

		link1 = add_link(source_node, dest_node, dist);
		if (type == BIDIR) {
			link2 = add_link(dest_node, source_node, dist);
		}
		update_links(source_node, link1);
		update_links(source_node, link2);
	}

	print_nodes();

	return 0;
}