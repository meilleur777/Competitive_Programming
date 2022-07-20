#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, r;
		cin >> n >> r;
		vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(n, vector<bool>(4, false)));
		set<intp> st;
		while (r--) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			st.insert({a, b});
		}
		int y, x;
		cin >> y >> x;
		y--, x--;
		function<bool(int, int)> chk=[&](int y, int x) {
			return y<n && y>=0 && x<n && x>=0;
		};
		int dis=-1;
		vector<int> dy({-1, 0, 1, 0}), dx({0, 1, 0, -1});
		rep(d, 4) {
			if (chk(y+dy[d], x+dx[d])) {
				y+=dy[d];
				x+=dx[d];
				dis=d;
				break;
			}
		}

		while (true) {
			if (!chk(y, x)) {
				cout << y+1 << ' ' << x+1 << '\n';
				break;
			}
			if (vis[y][x][dis]) {
				cout << 0 << ' ' << 0 << '\n';
				break;
			}
			vis[y][x][dis]=true;
			if (st.find({y, x})!=st.end()) dis=(dis+1)%4;;
			y+=dy[dis];
			x+=dx[dis];
		}
	}

	return 0;
}
