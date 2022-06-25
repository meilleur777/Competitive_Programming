#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

string p, a;
vector<vector<int>> dp;

int sol(int pp, int aa) {
	if (pp==p.size()) return aa==a.size();
	int& ret=dp[pp][aa];
	if (ret!=-1) return ret;
	ret=0;
	if (p[pp]=='*') {
		ret=max(ret, sol(pp+1, aa));
		if (aa<a.size()) {
			ret=max(ret, sol(pp, aa+1));
			ret=max(ret, sol(pp+1, aa+1));
		}
	}
	else {
		if (aa<a.size() && p[pp]==a[aa]) ret=max(ret, sol(pp+1, aa+1));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> p >> n;
	while (n--) {
		cin >> a;
		dp=vector<vector<int>>((int)p.size()+1, vector<int>((int)a.size()+1, -1));
		if (sol(0, 0)==1) cout << a << '\n';
	}

	return 0;
}
