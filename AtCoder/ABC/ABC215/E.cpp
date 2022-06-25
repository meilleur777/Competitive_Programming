#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod = 998244353;

int N;
string S;
int cache[1001][1100][12];

int solve(int now, int state, int last) {
	if (now == N) {
		return 1;
	}

	int& ret = cache[now][state][last]; 
	if (ret != -1) return ret;

	ret = 0;
	if (last == S[now] - 'A' + 1 || (state & (1 << (S[now] - 'A'))) == 0) {
		ret += solve(now + 1, state | (1 << (S[now] - 'A')), S[now] - 'A' + 1);
		ret %= mod;
	} 	
	ret += solve(now + 1, state, last);
	ret %= mod;

	return ret;
}

int main() {
	init_code();

	memset(cache, -1, sizeof(cache));

	cin >> N >> S;
	cout << solve(0, 0, 0) - 1;

	return 0;
}
