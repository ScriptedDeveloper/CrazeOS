#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef struct Node {
	struct Node *next_node;
	size_t size;
	bool free;
} Node;

Node* allocate_node(size_t size, struct Node *n);
Node* remove_node(Node *n);
void* malloc(size_t size);
void free(void* pointer);
void heap_init();
