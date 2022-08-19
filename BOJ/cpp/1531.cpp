#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(100, vector<int>(100, 0));
	while (n--) {
		int q, w, e, r;
		cin >> q >> w >> e >> r;
		for (int i=q-1; i<e; i++) {
			for (int j=w-1; j<r; j++) {
				a[i][j]++;
			}
		}
	}
	int ans=0;
	rep(i, 100) rep(j, 100) ans+=a[i][j]>m;
	cout << ans;

	return 0;
}
