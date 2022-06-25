#include <limits>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const long long NEGINF = numeric_limits<ll>::min();

int n, m;
int A[101], B[101];
int cache[102][102];

int solve(int a, int b) {
	int& ret = cache[a + 1][b + 1];
	if (ret != -1) return ret;
	
	ret = 0;
	long long ta = (a == -1) ? NEGINF : A[a];
	long long tb = (b == -1) ? NEGINF : B[b];
	long long current = max(ta, tb);
	
	for (int i = a + 1; i < n; i++) if (current < A[i]) ret = max(ret, solve(i, b) + 1);
	for (int i = b + 1; i < m; i++) if (current < B[i]) ret = max(ret, solve(a, i) + 1);
	return ret;	
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		cin >> n >> m;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++) cin >> A[i];
		for (int i = 0; i < m; i++) cin >> B[i];
		cout << solve(-1, -1) << '\n';
	}
}

