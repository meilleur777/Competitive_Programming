#include <stdio.h>

/*dp1, dp2로 각각의 방향에서 가장 긴 증가하는 부분 수열을 찾는다.
가장 긴 증가하는 부분 수열의 시간 복잡도 O(N^2)을 두 번 수행하므로 
시간복잡도는 여전히 O(N^2)이다.*/

int main() {
	int A[1001], dp1[1001] = { 1 }, dp2[1001], N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	dp2[N - 1] = 1;
	for (int i = 0; i < N; i++) {
		int max = 0;
		for (int j = i - 1; j >= 0; j--) 
            if (A[j] < A[i]) max = max > dp1[j] ? max : dp1[j];
		dp1[i] = max + 1;
		
		max = 0;
		for (int j = N - 1; j > N - 1 - i; j--) 
            if (A[j] < A[N - 1 - i]) max = max > dp2[j] ? max : dp2[j];
		dp2[N - i - 1] = max + 1;
	}
	
	int ans = -1;
	for (int i = 0; i < N; i++) 
        ans = ans > dp1[i] + dp2[i] ? ans : dp1[i] + dp2[i];
	printf("%d\n", ans - 1);
}

