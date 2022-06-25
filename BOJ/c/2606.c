#include <stdio.h>

int check[101] = { 0 };
int arrNum[101] = { 0 };
int arr[101][101];

int dfs(int V) {
	int i, count = 1;
	check[V] = 1;
	for (i = 0; i < arrNum[V]; i++) 
		if (!check[arr[V][i]]) count += dfs(arr[V][i]);
	return count;
}

int main() {
	int i, N, M;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][arrNum[a]++] = b;
		arr[b][arrNum[b]++] = a; 
	}
	
	printf("%d", dfs(1) - 1);
	
	return 0;
}
