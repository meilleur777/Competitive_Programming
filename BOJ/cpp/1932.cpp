#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) 

int triangle[501][501];

int main() {
	int N, res = -1; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}
	
    if (N == 1) {
        printf("%d\n", triangle[0][0]);
        return 0;
    }
    
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (!j) triangle[i][0] += triangle[i - 1][0];
			else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
			else triangle[i][j] += MAX(triangle[i - 1][j - 1], triangle[i - 1][j]);
			if (i == N - 1 && triangle[i][j] > res) res = triangle[i][j];
		}
	}
	printf("%d", res);
}
