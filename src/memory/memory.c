#include <stddef.h>
#include "memory.h"
#include "../string/string.h"

Node allocate_node(char *data, struct Node *n) {
	if(strcmp(n->next_node->data, "\0") == 0) { // making sure next node data is null terminated
		n->next_node->data = data;
		return *n;
	}
	return *n;
}
