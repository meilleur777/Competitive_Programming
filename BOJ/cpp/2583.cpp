#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
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

int num=0;
int M, N, K;
bool boa[101][101]={false};
int vis[101][101]={0};
int dy[4]={0, 0, -1, 1};
int dx[4]={1, -1, 0, 0};

void DFS(int y, int x) {
	vis[y][x]=num;
	for (int i=0; i<4; i++) {
		int ny=y+dy[i], nx=x+dx[i];
		if (ny>=N || ny<0 || nx>=M || nx<0) continue;
		if (!vis[ny][nx] && !boa[ny][nx]) {
			DFS(ny, nx);
		}
	}
}

int main() {
	init_code();

	cin >> M >> N >> K;
	rep(i, K) {
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;
		for (int j=ax; j<bx; j++) {
			for (int k=ay; k<by; k++) {
				boa[j][k]=true;
			}
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (!vis[i][j] && !boa[i][j]) {
				num++;
				DFS(i, j);
			}
		}
	}
	vector<int> cnt(num+1, 0);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (!vis[i][j]) continue;
			cnt[vis[i][j]]++;
		}
	}
	sort(cnt.begin(), cnt.end());
	cout << num << '\n';
	for (int i=1; i<cnt.size(); i++) {
		cout << cnt[i] << ' ';
	}

	return 0;
}
