#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
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

const int INF=0x3F3F3F3F;

int N, P;
vector<int> cache;
vector<vector<int> > A;

int solve(int sta) {
	if (!P || (sta && __builtin_popcount(sta)>=P)) {
		return 0;
	}
	int& ret=cache[sta];
	if (ret!=-1) return ret;
	ret=INF;
	for (int i=0; i<N; i++) {
		if (sta&(1<<i)) continue;
		for (int j=0; j<N; j++) {
			if (!(sta&(1<<j))) continue;
			ret=min(ret, solve(sta|(1<<i))+A[j][i]);
		}
	}
	return ret;
}

int main() {
	init_code();

	cin >> N;
	cache=vector<int>((1<<N), -1);
	A=vector<vector<int> >(N, vector<int>(N));
	rep(i, N) rep(j, N) cin >> A[i][j];
	string t;
	cin >> t;
	int sta=0;
	for (int i=0; i<t.size(); i++) {
		if (t[i]=='Y') {
			sta|=(1<<i);
		}
	}
	cin >> P;
	int res=solve(sta);
	if (res==INF) cout << -1;
	else cout << res;

	return 0;
}
