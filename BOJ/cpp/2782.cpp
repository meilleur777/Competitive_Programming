#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
    vector<int> dy({0, 0, 1, -1}), dx({1, -1, 0, 0});
	int inf=1e6;
    
	while (t--) {
		int n, m, b;
		cin >> n >> m >> b;
		vector<string> a(n);
		rep(i, n) cin >> a[i];
		intp K, Q;
		vector<intp> v;
		rep(i, n) rep(j, m) {
			if (a[i][j]=='K') K={i, j};
			if (a[i][j]=='Q') Q={i, j};
			if (a[i][j]=='G') v.push_back({i, j});
		}
		int cnt=v.size();
		v.push_back(K);
		v.push_back(Q);

		// 0~cnt-1->present, cnt->king, cnt+1->queen
		vector<vector<int>> dis;
		vector<vector<int>> edge(cnt+2, vector<int>(cnt+2));
		for (int i=0; i<cnt+2; i++) {
			dis=vector<vector<int>>(n, vector<int>(m, inf));
			dis[v[i].first][v[i].second]=0;
			queue<intp> q;
			q.push(v[i]);

			while (!q.empty()) {
				auto [y, x]=q.front();
				q.pop();
				rep(d, 4) {
					int ny=y+dy[d], nx=x+dx[d];
					if (ny>=n || ny<0 || nx>=m || nx<0) continue;
					if (a[ny][nx]=='#') continue;
					if (dis[ny][nx]==inf) {
						dis[ny][nx]=dis[y][x]+1;
						q.push({ny, nx});
					}
				}
			}
			for (int j=0; j<cnt+2; j++) {
				edge[i][j]=dis[v[j].first][v[j].second];
			}
		}

		vector<vector<int>> dp(cnt, vector<int>((1<<cnt), -1));
		function<int(int, int)> sol=[&](int now, int sta) {
			int spd=__builtin_popcount(sta)+1;
			if (spd==2) return edge[cnt][now];

			int& ret=dp[now][sta];
			if (ret!=-1) return ret;
			ret=inf;

			for (int nxt=0; nxt<cnt; nxt++) {
				if (nxt==now) continue;
				if (!(sta&(1<<nxt))) continue;
				ret=min(ret, edge[now][nxt]*(spd-1)+sol(nxt, (sta&(~(1<<now)))));
			}
			return ret;
		};

		int ans=0;
		for (int j=(1<<cnt)-1; j>0; j--) {
			int www=__builtin_popcount(j);
            
			for (int i=0; i<cnt; i++) {
				if (!(j&(1<<i))) continue;

				int tmp=sol(i, j)+edge[i][cnt+1]*(www+1);
				if (tmp<inf && tmp<=b) {
					ans=max(ans, www);
				}
			}
		}
		cout << ans << '\n';
 	}

	return 0;
}
