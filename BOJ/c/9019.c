#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	struct _node* parent;
	int value;
	char order;
} node;

int check[10010];
int front, back, rback;
node que[500010];
char res[10010];

int main() {
	int i, T; scanf("%d", &T);
	for (i = 0; i < T; i++) {
		int j, fut, A, B; scanf("%d %d", &A, &B);

		memset(check, 0, sizeof(int) * 10001);
		front = back = 0; rback = 0;
		node* temp = &que[back];
		que[back].parent = NULL;
		que[back++].value = A;
		check[A] = 1;
		
		while (front < back) {
			temp = &que[front++];
			int val = temp->value;
			if (val == B) break;
			
            if ((fut = val * 2) > 9999) fut %= 10000;
			if (!check[fut]) {
                check[fut] = 1;
				que[back].parent = temp;
				que[back].order = 'D';
				que[back++].value = fut;
			}
			
			if (!val) fut = 9999;
			else fut = val - 1;
			if (!check[fut]) {
                check[fut] = 1;
				que[back].parent = temp;
				que[back].order = 'S';
				que[back++].value = fut;
			}
			
			if (!check[fut = (val * 10 + val / 1000) % 10000]) {
                check[fut] = 1;
				que[back].parent = temp;
				que[back].order = 'L';
				que[back++].value = fut;
			}
			
			if (!check[fut = (val * 1000 + val / 10) % 10000]) {
                check[fut] = 1;
				que[back].parent = temp;
				que[back].order = 'R';
				que[back++].value = fut;
			}
		}
		
		while (temp->parent) {
			res[rback++] = temp->order;
			temp = temp->parent;
		}
		for (j = rback - 1; j >= 0; j--) printf("%c", res[j]);
		printf("\n");
	}
}

