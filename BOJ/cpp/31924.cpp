#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<string> brd(n);
	for (int i=0; i<n; i++) {
		cin >> brd[i];
	}

	string s="MOBIS";
	vector<int> dy({0, 0, 1, 1, 1, -1, -1, -1});
	vector<int> dx({1, -1, -1, 0, 1, -1, 0, 1});

	int ans=0;

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int d=0; d<8; d++) {
				function<int(int, int, int, int)> mobis=[&](int y, int x, int d, int now) {
					if (s[now]!=brd[y][x]) return 0;
					if (now==4) return 1;

					int ny=y+dy[d];
					int nx=x+dx[d];
					if (ny<0 || ny>=n || nx<0 || nx>=n) return 0;

					return mobis(ny, nx, d, now+1);
				};

				ans+=mobis(i, j, d, 0);
			}
		}
	}

	cout << ans;

	return 0;
}
