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

const int mod = 1e9 + 7;

string S;
string cho("chokudai");

int cache[8][100001];

int solve(int ptr, int now) {
	if (ptr == cho.size()) {
		return 1;
	}
	if (now == S.size()) {
		return 0;
	}

	int& ret = cache[ptr][now];
	if (ret != -1) return ret;

	ret = 0;
	if (S[now] == cho[ptr]) {
		ret += solve(ptr + 1, now + 1);
		ret %= mod;
	}
	ret += solve(ptr, now + 1);
	ret %= mod;

	return ret;
}


int main() {
	init_code();

	memset(cache, -1, sizeof(cache));

	cin >> S;
	cout << solve(0, 0);
}
