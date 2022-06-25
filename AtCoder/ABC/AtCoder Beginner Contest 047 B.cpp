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

	int main() {
		init_code();

		int w, h, n;
		cin >> w >> h >> n;
		vector<vector<bool>> brd(h, vector<bool>(w, false));
		rep(i, n) {
			int x, y, a;
			cin >> x >> y >> a;
			x--, y--;
			switch (a) {
				case 1: 
					for (int i=0; i<h; i++) {
						for (int j=0; j<=x; j++) {
							brd[i][j]=true;
						}
					}
					break;
				case 2:
					for (int i=0; i<h; i++) {
						for (int j=x+1; j<w; j++) {
							brd[i][j]=true;
						}
					}
					break;
				case 3:
					for (int i=0; i<=y; i++) {
						for (int j=0; j<w; j++) {
							brd[i][j]=true;
						}
					}
					break;
				case 4:
					for (int i=y+1; i<h; i++) {
						for (int j=0; j<w; j++) {
							brd[i][j]=true;
						}
					}
					break;
			}
		}
		int ans=0;
		rep(i, h) rep(j, w) {
			if (!brd[i][j]) ans++;
		}
		cout << ans;

		return 0;
	}
