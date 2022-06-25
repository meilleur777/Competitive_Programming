#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int n, m;
vector<int> a, b;
vector<vector<int>> dp;

int sol(int nn, int mm) {
	if (nn==n || mm==m) {
		return max(n-nn, m-mm);
	}
	int& ret=dp[nn][mm];
	if (ret!=-1) return ret;
	ret=INF;
	if (a[nn]==b[mm]) {
		ret=min(ret, sol(nn+1, mm+1));
	}
	else {
		ret=min(ret, 1+sol(nn+1, mm+1));
	}
	ret=min(ret, sol(nn+1, mm)+1);
	ret=min(ret, sol(nn, mm+1)+1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	a.resize(n), b.resize(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	dp=vector<vector<int>>(n, vector<int>(m, -1));
	cout << sol(0, 0);

	return 0;
}
