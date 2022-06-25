#include <stdio.h>
#define NUM 1000000007

int add(int a, int b) {
	return ((a % NUM) + (b % NUM)) % NUM;
}

int main() {
	int D; scanf("%d", &D);
	
	int arr[21][41] = { 0 };
	arr[1][1] = 1;
	for (int i = 2; i <= D; i++) {
		arr[i][i] = 1;
		if (i % 2 == 1) {
			for (int j = 1; j < i % 2 + 1; j++) {
				arr[i][j] = add(arr[i - 1][j], arr[i - 1][j + 1]);
			}
		}
		else if (i % 2 == 0) {
			arr[i][1] = arr[i - 1][1];
			for (int j = 2; j < i % 2 + 1; j++) {
				arr[i][j] = add(arr[i - 1][j - 1], arr[i - 1][j]);
			}
		}
	}
	printf("%d\n", arr[D]);
}

