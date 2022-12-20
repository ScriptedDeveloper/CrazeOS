#pragma once

typedef struct Node {
	struct Node *next_node;
	char *data;
} Node;

Node allocate_node(char *data, struct Node *n);
