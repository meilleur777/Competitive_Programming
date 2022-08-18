#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long long ld;
typedef pair<ll, ll> llp;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<llp> pos(n);
	rep(i, n) cin >> pos[i].first >> pos[i].second;

	vector<vector<ld>> dis(n, vector<ld>(n));
	rep(i, n) rep(j, n) {
		auto sqr=[&](ld a) { return a*a; };
		dis[i][j]=sqrtl(sqr(pos[i].first-pos[j].first)+sqr(pos[i].second-pos[j].second));
	}
	rep(i, n) sort(dis[i].begin(), dis[i].end());

	ld mx=1e10;
	llp ans;
	for (int i=0; i<n; i++) {
		if (dis[i].back()<mx) {
			ans=pos[i];
			mx=dis[i].back();
		}
	}	
	cout << ans.first << ' ' << ans.second;

	return 0;
}
