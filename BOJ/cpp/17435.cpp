#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int m;
	cin >> m;
	vector<vector<int>> a(20, vector<int>(m+1));
	rep(i, m) {
		cin >> a[0][i+1];
	}
	for (int i=1; i<20; i++) {
		for (int j=1; j<=m; j++) {
			a[i][j]=a[i-1][a[i-1][j]];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int n, x;
		cin >> n >> x;
		int now=x;
		for (int i=0; i<20; i++) {
			if (n&(1<<i)) {
				now=a[i][now];
			}
		}
		cout << now << '\n';	
	}

	return 0;
}
