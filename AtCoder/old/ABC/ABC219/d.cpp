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

int n, x, y;
vector<int> a, b;
vector<vector<vector<int>>> dp;

int sol(int now, int hasx, int hasy) {
	if (now==n) {
		if (hasx>=x && hasy>=y) return 0;
		return INF;
	}
	int& ret=dp[now][hasx][hasy];
	if (ret!=-1) return ret;
	ret=INF;
	ret=min(ret, sol(now+1, hasx, hasy));
	ret=min(ret, sol(now+1, min(x, hasx+a[now]), min(y, hasy+b[now]))+1);
	return ret;
}

int main() {
	init_code();

	cin >> n >> x >> y;
	dp=vector<vector<vector<int>>>(n, vector<vector<int>>(x+1, vector<int>(y+1, -1)));
	a.resize(n), b.resize(n);
	rep(i, n) cin >> a[i] >> b[i];
	int tmp=sol(0, 0, 0);
	if (tmp==INF) cout << -1;
	else cout << tmp;

	return 0;
}
