#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int pr, pc;
	cin >> pr >> pc;
	pr--, pc--;
	int mx=-1, mi;
	string dir("URDL");
	vector<int> dy({-1, 0, 1, 0}), dx({0, 1, 0, -1});
	map<pair<int, char>, int> mp;
	mp[{0, '/'}]=mp[{2, '/'}]=mp[{1, '\\'}]=mp[{3, '\\'}]=1;
	mp[{0, '\\'}]=mp[{2, '\\'}]=mp[{1, '/'}]=mp[{3, '/'}]=-1;
	auto sol=[&](int d) {
		int y=pr, x=pc;
		int ret=0;
		while (true) {
			y+=dy[d];
			x+=dx[d];
			ret++;
			if (ret>m*n*2) return -1;
			if (y>=n || y<0 || x>=m || x<0) return ret;
			if (s[y][x]=='C') return ret;
			else if (s[y][x]!='.') {
				d=(d+8+mp[{d, s[y][x]}])%4;
			}
		}
	};
	for (int i=0; i<4; i++) {
		int t=sol(i);
		if (t==-1) {
			cout << dir[i] << "\nVoyager";
			return 0;
		}
		if (mx<t) {
			mx=t;
			mi=i;
		}
	}
	cout << dir[mi] << ' ' << mx;

	return 0;
}
