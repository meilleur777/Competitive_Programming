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

string n;
vector<int> a;
vector<vector<int>> dp;

int sol(int now, int nxt) {
	if (now==a.size()) {
		return min(nxt, 1+10-nxt);
	}
	int& ret=dp[now][nxt];
	if (ret!=-1) return ret;
	ret=INF;
	int w=a[now]+nxt;
	if (w>=10) {
		nxt=w/10;
		w%=10;
	}
	else nxt=0;
	if (w==1) ret=min(ret, sol(now+1, nxt)+1);
	ret=min(ret, sol(now+1, nxt)+w);
	ret=min(ret, sol(now+1, nxt+1)+10-w);
	return ret;

}

int main() {
	init_code();

	cin >> n;
	reverse(n.begin(), n.end());
	for (auto i:n) a.push_back(i-'0');
	dp=vector<vector<int>>(n.size(), vector<int>(5, -1));
	cout << sol(0, 0);

	return 0;
}
