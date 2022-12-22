#include <stddef.h>
#include "memory.h"
#define BLOCK_SIZE 1024
Node *n = (Node*)0x200000;

Node* allocate_node(size_t size, struct Node *curr_n) {
	curr_n->free = false;
	for(size_t i = 0; i<= size; i++) {
		size_t size_ = size;
		if(curr_n->size == 0) {
			n->size = BLOCK_SIZE;
			n = n->next_node;
			continue;
		}
		n->next_node->size = BLOCK_SIZE;
		curr_n = n->next_node;
	}	
	return n;
}

Node* remove_node(Node *cur_n) {
	Node *next_n = (Node*)&n;
	while((Node*)&cur_n != next_n) {
		cur_n = (Node*)&next_n->next_node;
	}
	cur_n->free = true;
	return cur_n;
}

void* malloc(size_t size) {
	while(!n->free) {
		n = (Node*)&n->next_node;
	}
	return (void*)allocate_node(size, n);
}

void free(void* pointer) {
	remove_node((Node*)pointer);
}

void heap_init() {
	Node *next_n = n;
	while(next_n < (Node*)0x300000) {
		next_n->free = true; // freeing all memory
		next_n->next_node = (Node*)next_n + 1; // setting memory address
		next_n = next_n->next_node;
	}
}
