#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int m, n;
	cin >> m >> n;
	int u, l, r, d;
	cin >> u >> l >> r >> d;
	vector<string> word(m);
	for (int i=0; i<m; i++) {
		cin >> word[i];
	}

	vector<string> brd((u+d+m), string(l+r+n, '.'));
	for (int i=0; i<(u+d+m); i++) {
		for (int j=0; j<(l+r+n); j++) {
			if ((i+j)%2==0) {
				brd[i][j]='#';
			}
		}
	}

	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			brd[i+u][j+l]=word[i][j];
		}
	}

	for (auto s:brd) {
		cout << s << '\n';
	}

	return 0;
}
