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

vector<ld> p;
vector<vector<ld> > cache;

ld solve(int now, int hcnt) {
	if (now==p.size()) {
		if (hcnt>p.size()/2) {
			return 1.0;
		}
		else {
			return 0.0;
		}
	}
	ld& ret=cache[now][hcnt];
	if (ret!=-1) return ret;
	ret=0.0;
	ret+=solve(now+1, hcnt+1)*p[now];
	ret+=solve(now+1, hcnt)*(1.0-p[now]);
	return ret;
}

int main() {
	init_code();
	cout << fixed;
	cout.precision(10);

	int N;
	cin >> N;
	p.resize(N);
	cache=vector<vector<ld> >(N, vector<ld>(N+1, -1));
	rep(i, N) cin >> p[i];
	cout << solve(0, 0);

	return 0;
}
