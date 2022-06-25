#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<int> a(25, 1);
	vector<string> s(5);
	rep(i, 5) cin >> s[i];
	rep(i, 18) a[i]=0;
	int ans=0;
	int dy[4]={0, 0, -1, 1};
	int dx[4]={1, -1, 0, 0};
	do {
		vector<vector<bool>> sel(5, vector<bool>(5, false));
		int ycnt=0, scnt=0;
		rep(i, 25) {
			sel[i/5][i%5]=a[i];
			if (a[i]) {
				ycnt+=s[i/5][i%5]=='Y';
				scnt+=s[i/5][i%5]=='S';
			}
		}
		if (scnt<ycnt) continue;
		bool flag=false;
		vector<vector<bool>> vis(5, vector<bool>(5, false));
		function<void(int, int)> dfs=[&](int y, int x) {
			vis[y][x]=true;
			rep(d, 4) {
				int ny=y+dy[d], nx=x+dx[d];
				if (ny>=5 || ny<0 || nx>=5 || nx<0) continue;
				if (sel[ny][nx] && !vis[ny][nx]) dfs(ny, nx);
			}
		};
		auto chk=[&]() {
			rep(i, 5) rep(j, 5) {
				if (!vis[i][j] && sel[i][j]) {
					if (flag) return false;
					else {
						flag=true;
						dfs(i, j);
					}
				}
			}
			return true;
		};
		ans+=chk();
	} while (next_permutation(a.begin(), a.end()));
	cout << ans;

	return 0;
}
