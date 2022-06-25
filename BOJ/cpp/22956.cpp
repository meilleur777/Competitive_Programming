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

int brd[1002][1002];
vector<vector<bool> > wat;
vector<vector<intp> > par;
vector<vector<pair<intp, intp> > > best;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

intp find(intp a) {
	if (a==par[a.first][a.second]) return a;
	return par[a.first][a.second]=find(par[a.first][a.second]);
}

intp merge(intp a, intp b) {
	a=find(a), b=find(b);
	if (a==b) return best[a.first][a.second].second;
	pair<intp, intp>& ba=best[a.first][a.second], bb=best[b.first][b.second];
	if (ba.first.first<bb.first.first) {
		par[b.first][b.second]=a;
		return ba.second;
	}
	else if (ba.first.first==bb.first.first) {
		if (ba.first.second<bb.first.second) {
			par[b.first][b.second]=a;
			return ba.second;
		}
		else {
			par[a.first][a.second]=b;
			return bb.second;
		}
	}
	else {
		par[a.first][a.second]=b;
		return bb.second;
	}
}

int main() {
	init_code();

	int N, M, Q;
	cin >> N >> M >> Q;
	par=vector<vector<intp> >(N+1, vector<intp>(M+1));
	wat=vector<vector<bool> >(N+1, vector<bool>(M+1, false));
	best=vector<vector<pair<intp, intp> > >(N+1, vector<pair<intp, intp> >(M+1));
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=M; j++) {
			par[i][j]={i, j};
			cin >> brd[i][j];
		}
	}
	int day=0;
	while (Q--) {
		int a, b, c;
		cin >> a >> b >> c;
		brd[a][b]-=c;
		if (wat[a][b]==true) {
			intp t=find({a, b});
			if (best[t.first][t.second].first.first>brd[a][b]) {
				best[t.first][t.second]={{brd[a][b], day}, {a, b}};
			}	
		}
		else {
			wat[a][b]=true;
			best[a][b]={{brd[a][b], day}, {a, b}};
		}
		intp res=best[a][b].second;
		for (int i=0; i<4; i++) {
			int ny=a+dy[i], nx=b+dx[i];
			if (ny>N || ny<1 || nx>M || nx<1) continue;
			if (wat[ny][nx]==true) {
				res=merge({a, b}, {ny, nx});
			}
		}
		day++;
		cout << res.first << ' ' << res.second << '\n';
	}

	return 0;
}
