#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;

int N, A[102], psum[102], pSqSum[102], cache[102][11];

void precalc() {
	psum[0] = pSqSum[0] = 0;
	memset(cache, -1, sizeof(cache));
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; i++) {
		psum[i] = psum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}

int minError(int lo, int hi) {
	int sum = psum[hi] - psum[lo - 1];
	int sqSum = pSqSum[hi] - pSqSum[lo - 1];
	int m = int(0.5 + (double)sum / (hi - lo + 1));
	return sqSum - 2 * m * sum + m * m * (hi - lo + 1);
}

int solve(int ptr, int remain) {
	if (ptr == N + 1) return 0;
	if (!remain) return INF;
	int& ret = cache[ptr][remain];
	if (ret != -1) return ret;
	ret = INF;
	for (int partSize = 1; ptr + partSize <= N + 1; partSize++) 
		ret = min(ret, minError(ptr, ptr + partSize - 1) + solve(ptr + partSize, remain - 1));
	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
		
	int C; cin >> C;
	while (C--) {
		int S; cin >> N >> S;
		for (int i = 1; i <= N; i++) cin >> A[i];
		precalc();
		cout << solve(1, S) << '\n';
	}
}

