#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	struct _node *parent;
	struct _node *left;
	struct _node *right;
	int key;
} node;

node *create(node *root, int value) {
	node *temp = (node *)malloc(sizeof(node));
	temp->parent = root;
	temp->key = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void add(node *root, int value) {
	if (root->key > value) {
		if (root->left) add(root->left, value);
		else root->left = create(root, value);		
	}
	else {
		if (root->right) add(root->right, value);
		else root->right = create(root, value);
	}
}

void traverse(node *root) {
	if (root->left) traverse(root->left);	
	if (root->right) traverse(root->right);
	printf("%d\n", root->key);
}

int main() {
	int t; scanf("%d", &t);
	node *root = create(NULL, t);
	while (scanf("%d", &t) != EOF) add(root, t);
	traverse(root);
}

