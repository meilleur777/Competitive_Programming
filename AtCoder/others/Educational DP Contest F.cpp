#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

string s, t;
vector<vector<int> > cache;

int solve(int a, int b) {
	if (a==s.size() || b==t.size()) {
		return 0;
	}
	int& ret=cache[a][b];
	if (ret!=-1) return ret;
	ret=0;
	if (s[a]==t[b]) {
		return ret=max(ret, solve(a+1, b+1)+1);
	}
	ret=max(ret, solve(a+1, b));
	ret=max(ret, solve(a, b+1));
	return ret;
}

string recon(int a, int b) {
	if (a==s.size() || b==t.size()) {
		return "";
	}
	if (s[a]==t[b] && solve(a, b)==solve(a+1, b+1)+1) {
		return s[a]+recon(a+1, b+1);
	}
	if (solve(a+1, b)>solve(a, b+1)) {
		return recon(a+1, b);
	}
	return recon(a, b+1);
}

int main() {
	init_code();

	cin >> s >> t;
	cache=vector<vector<int> >(s.size(), vector<int>(t.size(), -1));
	cout << recon(0, 0);

	return 0;
}
