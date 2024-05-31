#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int n;
	cin >> n;
	vector<int> cnt(26, INF);
	rep(i, n) {
		string s;
		cin >> s;
		vector<int> tmp(26, 0);
		for (auto j:s) {
			tmp[j-'a']++;
		}
		rep(j, 26) {
			cnt[j]=min(cnt[j], tmp[j]);
		}
	}
	string res;
	for (int i=0; i<26; i++) {
		if (cnt[i]!=INF) {
			rep(j, cnt[i]) res+=char(i+'a');
		}
	}
	cout << res;

	return 0;
}
