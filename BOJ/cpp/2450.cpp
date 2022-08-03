#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	vector<int> cnt(3, 0);
	rep(i, n) cnt[a[i]-1]++;
	vector<int> pm({1, 2, 3});
	int ans=1e5;
	do {
		vector<int> b;
		vector<vector<int>> www(3, vector<int>(3, 0));
		rep(i, 3) rep(j, cnt[pm[i]-1]) b.push_back(pm[i]);
		int tmp=0;
		rep(i, n) {
			if (a[i]!=b[i]) {
				www[a[i]-1][b[i]-1]++;
			}
		}
		rep(i, 3) rep(j, 3) {
			if (i==j) continue;
			int qqq=min(www[i][j], www[j][i]);
			tmp+=qqq;
			www[i][j]-=qqq;
			www[j][i]-=qqq;
		}
		int ttt=0;
		rep(i, 3) rep(j, 3) {
			ttt+=www[i][j];
		}
		tmp+=ttt/3*2;
		ans=min(ans, tmp);
	}
	while (next_permutation(pm.begin(), pm.end()));
	cout << ans;

	return 0;
}
