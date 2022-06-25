#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void upperHeapify(int *arr, int number, int child) {
	int root = (child - 1) / 2;
	int leftChild = root * 2 + 1;
	int rightChild = leftChild + 1;
	int winner = leftChild;
	if (root >= 0) {
		if (number > rightChild)  
			winner = (arr[leftChild] > arr[rightChild]) ? leftChild : rightChild;
		if (arr[root] < arr[winner]) swap(arr + root, arr + winner);
		if (root > 0) upperHeapify(arr, number, root);
	}
}

void lowerHeapify(int *arr, int number, int root) {
	int leftChild = root * 2 + 1;
	int rightChild = leftChild + 1;
	int winner = leftChild;
	if (leftChild < number) {
		if (rightChild < number) 
			winner = (arr[leftChild] > arr[rightChild]) ? leftChild : rightChild;
		if (arr[root] < arr[winner]) swap(arr + root, arr + winner);
		if (winner < number / 2) lowerHeapify(arr, number, winner);
	}
}

void add(int *arr, int number, int key) {
	arr[number++] = key;
	upperHeapify(arr, number, number - 1);
}

int pop(int *arr, int number) {
	swap(arr, arr + number - 1);
	lowerHeapify(arr, number - 1, 0);	
	return arr[number - 1];
}

int main() {
	int i, N, input;
	int number = 0, arr[100001];
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%d", &input);
		if (input) add(arr, number++, input);
		else if (!number) printf("0\n");
		else printf("%d\n", pop(arr, number--));
	}
	
	return 0;
}
