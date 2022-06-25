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

int S;
vector<vector<int> > dp;	

int solve(int now, int brd) {
	if (now>=S) {
		return now-S;
	}
	int& ret=dp[now][brd];
	if (ret!=-1) return ret;
	ret=INF;
	ret=min(ret, solve(now, now)+1);
	if (brd!=0) {
		ret=min(ret, solve(now+brd, brd)+1);
	}
	if (now>0) {
		ret=min(ret, solve(now-1, brd)+1);
	}
	return ret;	
}

int main() {
	init_code();

	cin >> S;
	dp=vector<vector<int> >(S+1, vector<int>(S+1, -1));
	cout << solve(1, 0);

	return 0;
}
