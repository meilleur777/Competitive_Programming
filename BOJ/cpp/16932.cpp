#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	rep(i, n) rep(j, m) cin >> a[i][j];

	vector<vector<intp>> par(n, vector<intp>(m));
	rep(i, n) rep(j, m) par[i][j]={i, j};

	map<intp, int> siz;
	rep(i, n) rep(j, m) siz[{i, j}]=1;

	function<intp(intp)> find=[&](intp qq) {
		int y=qq.first, x=qq.second;
		if (par[y][x]==qq) return qq;
		return par[y][x]=find(par[y][x]);
	};

	function<void(int, int, int, int)> merge=[&](int ay, int ax, int by, int bx) {
		auto aa=find(make_pair(ay, ax));
		auto bb=find(make_pair(by, bx));
		if (aa==bb) return;
		par[bb.first][bb.second]=aa;
		siz[aa]+=siz[bb];
	};

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!a[i][j]) continue;
			if (i!=n-1) {
				if (a[i+1][j]) {
					merge(i, j, i+1, j);
				}
			}
			if (j!=m-1) {
				if (a[i][j+1]) {
					merge(i, j, i, j+1);
				}
			}
		}
	}

	vector<int> dy({0, 0, -1, 1}), dx({1, -1, 0, 0});

	int ans=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (a[i][j]) continue;
			set<intp> st;
			rep(d, 4) {
				int ny=i+dy[d];
				int nx=j+dx[d];
				if (ny>=n || ny<0 || nx>=m || nx<0) {
					continue;
				}
				if (a[ny][nx]==1) {
					st.insert(find({ny, nx}));
				}
			}
			int tmp=1;
			for (auto ww:st) {
				tmp+=siz[ww];
			}
			ans=max(ans, tmp);
		}
	}
	cout << ans;

	return 0;
}
