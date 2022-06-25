#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int R, C;
int num;
vector<intp> clu;
vector<string> cave;
vector<vector<int> > vis;
vector<int> dy({0, 0, -1, 1});
vector<int> dx({1, -1, 0, 0});

bool inRange(int y, int x) {
	return (y < R && y >= 0 && x < C && x >= 0);
}

void DFS(int y, int x) {
	vis[y][x] = num;
	clu.push_back({y, x});
	rep(i, 4) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!inRange(ny, nx)) continue;
		if (cave[ny][nx] == 'x' && vis[ny][nx] == 0) {
			DFS(ny, nx);
		}
	}
}

bool cpr(intp& a, intp& b) {
	return a.first > b.first;
}

void fall(int sy, int sx) {
	num = 0;
	rep(i, 4) {
		int ny = sy + dy[i], nx = sx + dx[i];
		if (!inRange(ny, nx)) continue;
		vis = vector<vector<int> >(R, vector<int>(C, 0));
		if (cave[ny][nx] == 'x' && vis[ny][nx] == 0) {
			num++;
			clu.clear();
			DFS(ny, nx);
			sort(clu.begin(), clu.end(), cpr);
			int tofall = INT_MAX;
			bool ok = false;	/*check whether cluster has to fall*/
			for (intp j : clu) {
				if (j.first == R-1) {
					ok = true;
					break;	
				}
				bool chk = true;
				int ty = j.first+1;
				if (vis[ty][j.second] == vis[j.first][j.second]) {
					chk = false;
				}
				while (inRange(ty, j.second) && (cave[ty][j.second] == '.' ||
					 (vis[ty][j.second] == vis[j.first][j.second]))) {
					if (vis[ty][j.second] == vis[j.first][j.second]) {
						chk = false;
						break;
					}
					ty++;
				}
				ty--;
				if (!chk) continue;
				tofall = min(tofall, ty-j.first);
			}
			if (ok) continue;
			for (intp j : clu) {
				cave[j.first][j.second] = '.';
				cave[j.first+tofall][j.second] = 'x';
			}
		}
	}
}

int main() {
	init_code();

	int N;
	cin >> R >> C;
	cave.resize(R);
	rep(i, R) {
		cin >> cave[i];
	}
	cin >> N;
	rep(i, N) {
		int h;
		cin >> h;
		h = R-h;
		/*right to left*/
		if (i%2) {
			for (int j = C-1; j >= 0; j--) {
				if (cave[h][j] == 'x') {
					cave[h][j] = '.';
					fall(h, j);
					break;
				}
			}
		}
		/*left to right*/
		else {
			for (int j = 0; j < C; j++) {
				if (cave[h][j] == 'x') {
					cave[h][j] = '.';
					fall(h, j);
					break;
				}
			}
		}
	}
	for (auto i : cave) {
		cout << i << '\n';
	}

	return 0;
}
