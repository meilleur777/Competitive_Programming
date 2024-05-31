#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

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

int main() {
	init_code();

	int N, Q;
	cin >> N >> Q;
	string S;
	cin >> S;
	S = 'E'+S;
	vector<int> cnt(N+1, 0);
	for (int i = 1; i < S.size()-1; i++) {
		if (S[i] == 'A' && S[i+1] == 'C') {
			cnt[i] = cnt[i+1] = 1;
			i++;
		}
	}
	for (int i = 1; i < S.size(); i++) {
		cnt[i] += cnt[i-1];
	}
	while (Q--) {
		int l, r;
		cin >> l >> r;
		int res = cnt[r]-cnt[l-1];
		if (res%2) {
			cout << res/2 << '\n';
		}
		else {
			if (S[r] == 'A' && S[r+1] == 'C') {
				res--;
			}
			if (S[l] == 'C' && S[l-1] == 'A') {
				res--;
			}
			cout << res/2 << '\n';
		}
	}

	return 0;
}
