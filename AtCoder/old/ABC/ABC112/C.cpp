#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

int dy[4]={0, 0, -1, 1};
int dx[4]={1, -1, 0, 0};

int main() {
	init_code();

	int N;
	cin >> N;
	vector<pair<intp, int> > cor;
	vector<intp> tra;
	rep(i, N) {
		int x, y, h;
		cin >> y >> x >> h;
		if (h==0) {
			tra.push_back({y, x});
		}
		else {
			cor.push_back({{y, x}, h});
		}
	}
	vector<vector<vector<int> > > vis(cor.size(), vector<vector<int> >(101, vector<int>(101, -1)));
	for (int i=0; i<cor.size(); i++) {
		queue<intp> q;
		q.push(cor[i].first);
		vis[i][cor[i].first.first][cor[i].first.second]=cor[i].second;
		while (!q.empty()) {
			intp now=q.front();
			q.pop();
			for (int d=0; d<4; d++) {
				int ny=now.first+dy[d], nx=now.second+dx[d];
				if (ny==101 || ny==-1 || nx==101 || nx==-1) continue;
				if (vis[i][ny][nx]==-1) {
					vis[i][ny][nx]=vis[i][now.first][now.second]+1;
					q.push({ny, nx});
				}
			}
		}
	}
	for (int i=0; i<=100; i++) {
		for (int j=0; j<=100; j++) {
			bool flag=true;
			int tmp=vis[0][i][j];
			for (int k=1; k<cor.size(); k++) {
				if (vis[k][i][j]!=tmp) {
					flag=false;
					break;
				}
			}
			if (flag) {
				bool ok=true;
				for (auto [y, x] : tra) {
					if (max(tmp-abs(i-y)-abs(j-x), 0)!=0) {
						ok=false;
						break;
					}
				}
				if (ok) {
					cout << i << ' ' << j << ' ' << tmp;
					return 0;
				}
			}
		}
	}

	return 0;
}
