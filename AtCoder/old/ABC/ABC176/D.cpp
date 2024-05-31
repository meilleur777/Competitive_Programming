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

const int dy[4]={0, 0, -1, 1};
const int dx[4]={1, -1, 0, 0};

int main() {
	init_code();

	int H, W;
	cin >> H >> W;
	intp C;
	cin >> C.first >> C.second;
	C.first--, C.second--;
	intp D;
	cin >> D.first >> D.second;
	D.first--, D.second--;
	vector<string> S(H);
	rep(i, H) cin >> S[i];
	vector<vector<int> > dis(H, vector<int>(W, INF));
	dis[C.first][C.second]=0;
	priority_queue<pair<int, intp>, vector<pair<int, intp> >, greater<pair<int, intp> > > pq;
	pq.push({0, {C.first, C.second}});
	while (!pq.empty()) {
		int cos=pq.top().first;
		intp now=pq.top().second;
		if (now==D) {
			cout << cos;
			return 0;
		}
		pq.pop();
		for (int i=0; i<4; i++) {
			int ny=now.first+dy[i], nx=now.second+dx[i];
			if (ny>=H || ny<0 || nx>=W || nx<0) continue;
			if (S[ny][nx]=='#') continue;
			if (dis[ny][nx]>cos) {
				dis[ny][nx]=cos;
				pq.push({dis[ny][nx], {ny, nx}});
			}
		}
		for (int i=-2; i<3; i++) {
			for (int j=-2; j<3; j++) {
				int ny=now.first+i, nx=now.second+j;
				if (ny>=H || ny<0 || nx>=W || nx<0) continue;
				if (S[ny][nx]=='#') continue;	
				if (dis[ny][nx]>cos+1) {
					dis[ny][nx]=cos+1;
					pq.push({dis[ny][nx], {ny, nx}});
				}
			}
		}
	}
	cout << -1;

	return 0;
}
