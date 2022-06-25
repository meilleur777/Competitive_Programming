#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a; *a = *b; *b = temp;
}
	
void maxHeapify(int root) {
	int leftChild = root * 2 + 1;
	int rightChild = leftChild + 1;
	int winner = leftChild;

	if (leftChild < number) {
		if (rightChild < number)
			winner = heap[leftChild] > heap[rightChild] ? leftChild : rightChild;
		if (heap[root] < heap[winner]) swap(heap + root, heap + winner);
		if (winner > number / 2) maxHeapify(winner);
	}
}

void minHeapify(int root) {
	int leftChild = root * 2 + 1;
	int rightChild = leftChild + 1;
	int winner = leftChild;

	if (leftChild < number) {
		if (rightChild < number)
			winner = heap[leftChild] < heap[rightChild] ? leftChild : rightChild;
		if (heap[root] > heap[winner]) swap(heap + root, heap + winner);
		if (winner > number / 2) minHeapify(winner);
	}
}

int main() {
	int i, j, l, T; scanf("%d", &T);

	for (i = 0; i < T; i++) {
		int k; scanf("%d", &k);
		
		for (j = 0; j < k; j++) {
			int x; char ord; 
			scanf(" %c %d", &ord, &x);

			if (order == 'I') add(x);
			else if (order == 'D' && !empty()) {
				if (x == 1) deleteMax();
				else deleteMin();
			}
		}
	}
}
