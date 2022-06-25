#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool inRange(int y, int x, int N) {
	return (y<=N && y>0 && x<=N && x>0);
}

int main() {
	init_code();

	int N, M, P;
	cin >> N >> M >> P;
	vector<vector<int> > brd(N+1, vector<int>(N+1));
	rep(i, N) rep(j, N) cin >> brd[i+1][j+1];
	intp now;
	cin >> now.first >> now.second;
	map<intp, intp> ord;
	for (int i=0; i<M; i++) {
		int sx, sy, tx, ty;
		cin >> sy >> sx >> ty >> tx;
		brd[sy][sx]=3;
		ord.insert({{sy, sx}, {ty, tx}});
	}
	while (ord.size()>0) {
		vector<vector<int> > vis(N+1, vector<int>(N+1, -1));
		queue<intp> q;
		q.push({now.first, now.second});
		priority_queue<pair<int, intp>, vector<pair<int, intp> >, greater<pair<int, intp> > > pq;
		vis[now.first][now.second] = 0;
		while (!q.empty()) {
			int y=q.front().first, x=q.front().second;
			q.pop();
			if (vis[y][x]>P) {
				vis[y][x]=-1;
				continue;
			}
			if (brd[y][x]==3) {
				pq.push({vis[y][x], {y, x}});
			}
			for (int d=0; d<4; d++) {
				int ny=y+dy[d], nx=x+dx[d];
				if (!inRange(ny, nx, N) || brd[ny][nx]==1) continue;
				if (vis[ny][nx]==-1) {
					vis[ny][nx]=vis[y][x]+1;
					q.push({ny, nx});
				}
			}
		}
		if (pq.empty()) {
			cout << -1;
			return 0;
		}
		intp np=pq.top().second;
		brd[np.first][np.second]=0;
		P-=vis[np.first][np.second];
		map<intp, intp>::iterator temp=ord.find({np.first, np.second});
		intp dest = temp->second;
 		ord.erase(temp);
		while(q.size()) q.pop();
		q.push({np.first, np.second});
		vis=vector<vector<int> >(N+1, vector<int>(N+1, -1));
		vis[np.first][np.second] = 0;
		while (!q.empty()) {
			int y=q.front().first, x=q.front().second;
			q.pop();
			if (vis[y][x]>P) {
				vis[y][x]=-1;
				continue;
			}
			if (make_pair(y, x)==dest) {
				break;
			}
			for (int d=0; d<4; d++) {
				int ny=y+dy[d], nx=x+dx[d];
				if (!inRange(ny, nx, N) || brd[ny][nx]==1) continue;
				if (vis[ny][nx]==-1) {
					vis[ny][nx]=vis[y][x]+1;
					q.push({ny, nx});
				}
			}
		}
		if (vis[dest.first][dest.second]==-1) {
			cout << -1;
			return 0;
		}
		P+=vis[dest.first][dest.second];
		now=dest;
	}
	cout << P;

	return 0;
}
