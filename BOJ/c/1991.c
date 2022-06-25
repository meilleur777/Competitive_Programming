#include <stdio.h>

typedef struct _node {
	struct _node *parent;
	struct _node *left_child;
	struct _node *right_child;
	char key;
} node;

node tree[30];

void preorder_traversal(node *root) {
	printf("%c", root->key);
	if (root->left_child) preorder_traversal(root->left_child);
	if (root->right_child) preorder_traversal(root->right_child);
}

void inorder_traversal(node *root) {
	if (root->left_child) inorder_traversal(root->left_child);
	printf("%c", root->key);
	if (root->right_child) inorder_traversal(root->right_child);
}

void postorder_traversal(node *root) {
	if (root->left_child) postorder_traversal(root->left_child);
	if (root->right_child) postorder_traversal(root->right_child);
	printf("%c", root->key);
}

int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		tree[i].key = i + 'A';
		char ro, lc, rc;
		getchar();
		scanf("%c %c %c", &ro, &lc, &rc);
		if (lc != '.') tree[ro - 'A'].left_child = &tree[lc - 'A'];
		if (rc != '.') tree[ro - 'A'].right_child = &tree[rc - 'A'];
	}
	preorder_traversal(&tree[0]); printf("\n");
	inorder_traversal(&tree[0]); printf("\n");
	postorder_traversal(&tree[0]); printf("\n");
}

