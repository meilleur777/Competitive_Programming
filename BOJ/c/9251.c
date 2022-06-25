#include <stdio.h>
#include <string.h>

int arr[1001][1001] = { 0 };

int main() {
	char A[1001], B[1001];
	scanf("%s %s", A, B);
	int Alen = strlen(A);
	int Blen = strlen(B);
	int max = -1;
	for (int i = 0; i < Alen; i++) {
		for (int j = 0; j < Blen; j++) {
			if (A[i] == B[j]) arr[i + 1][j + 1] = arr[i][j] + 1;
			else arr[i + 1][j + 1] = 
				 arr[i][j + 1] > arr[i + 1][j] ? arr[i][j + 1] : arr[i + 1][j];
			max = max > arr[i + 1][j + 1] ? max : arr[i + 1][j + 1];
		}
	}
	printf("%d\n", max);
}

