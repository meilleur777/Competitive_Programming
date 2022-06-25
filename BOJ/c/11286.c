#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void upperHeapify(int *arr, int number, int child) {
    if (!child) return;
    
	int root = (child - 1) / 2;
	int leftChild = root * 2 + 1;
	int rightChild = root * 2 + 2;
	int winner = leftChild;
	
	if (root >= 0) {
		if (rightChild < number) 
			winner = (abs(arr[leftChild]) < abs(arr[rightChild])) ? leftChild : rightChild;
		if (abs(arr[root]) > abs(arr[winner])) swap(arr + root, arr + winner);
		if (root > 0) upperHeapify(arr, number, root);
	}	
}

void lowerHeapify(int *arr, int number, int root) {
	int leftChild = root * 2 + 1;
	int rightChild = leftChild + 1;
	int winner = leftChild;
	
	if (leftChild < number) {
		if (rightChild < number) 
			winner = (abs(arr[leftChild]) < abs(arr[rightChild])) ? leftChild : rightChild;
		if (abs(arr[root]) > abs(arr[winner])) swap(arr + root, arr + winner);
		if (winner < number / 2) lowerHeapify(arr, number, winner);
	}
}

void add(int *arr, int number, int value) {
	arr[number++] = value;
	upperHeapify(arr, number, number - 1);
}

int find(int *arr, int number, int root) {
	int leftChild = root * 2 + 1;
	int rightChild = leftChild + 1;
	int leftResult = root, rightResult = root;
	
	if (leftChild < number && abs(arr[leftChild]) == abs(arr[root])) 
		leftResult = find(arr, number, leftChild);
	if (rightChild < number && abs(arr[rightChild]) == abs(arr[root])) 
		rightResult = find(arr, number, rightChild);
	
	int result = (arr[leftResult] < arr[rightResult]) ? leftResult : rightResult;
	return (arr[result] < arr[root]) ? result : root;
}

int pop(int *arr, int number) {
	swap(arr, arr + find(arr, number--, 0));
	swap(arr, arr + number);
	lowerHeapify(arr, number, 0);	
	return arr[number];
}

int main() {
	int i, N, x;
	int arr[100001], number = 0;
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%d", &x);
		if (x) add(arr, number++, x);
		else if (!number) printf("0\n");
		else printf("%d\n", pop(arr, number--));
	}
	
	return 0;
}
