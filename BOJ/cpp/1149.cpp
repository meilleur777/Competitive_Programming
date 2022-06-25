#include <iostream>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;

int N, rgbs[1001][3], cache[1001][3];

int getMin(int type, int d) {
	if (d == N) return 0;
	
	int& ret = cache[d][type];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int i = 0; i < 3; i++) {
		if (i == type) continue;
		ret = min(ret, getMin(i, d + 1) + rgbs[d][type]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	fill_n(&cache[0][0], 1001 * 3, -1);
	for (int i = 0; i < N; i++) cin >> rgbs[i][0] >> rgbs[i][1] >> rgbs[i][2];
	int result = min({ getMin(0, 0), getMin(1, 0), getMin(2, 0) });
	cout << result << "\n";
}
