#include <iostream>
#include <string.h>
#define MOD 10000000
using namespace std;

int cache[101][101];

/*n개의 정사각형을 포함하되, 첫 줄에 first개의 정사각형이 들어가는 폴리노미오의 수*/
int solve(int n, int first) {
	if (n == first) return 1;
	
	int& ret = cache[n][first];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int second = 1; second + first <= n; second++) {
		ret += (second + first - 1) * solve(n - first, second) % MOD;
		ret %= MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
	
	int C; cin >> C;
	while (C--) {
		int n;
		cin >> n;
		int result = 0;
		for (int i = 1; i <= n; i++) {
			result += solve(n, i);
			result %= MOD;
		}
		cout << result << '\n';
	}	
}

