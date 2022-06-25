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

vector<vector<int> > b;

int swi(int x) {
	return x?0:1;
}

int n;
int dy[4]={0, 0, -1, 1};
int dx[4]={1, -1, 0, 0};

void but(int y, int x) {
	b[y][x]=swi(b[y][x]);
	for (int i=0; i<4; i++) {
		int ny=y+dy[i], nx=x+dx[i];
		if (ny>=n || ny<0 || nx>=n || nx<0) continue;
		b[ny][nx]=swi(b[ny][nx]);
	}
}

int main() {
	init_code();

	cin >> n;
	vector<vector<int> > a(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	int ans=INF;
	for (int i=0; i<(1<<n); i++) {
		b=a;
		int cnt=0;
		for (int j=0; j<n; j++) {
			if (i&(1<<j)) {
				but(0, j);
				cnt++;
			}
		}
		for (int j=1; j<n; j++) {
			for (int k=0; k<n; k++) {
				if (b[j-1][k]==1) {
					but(j, k);
					cnt++;
				}
			}
		}
		bool flag=true;
		for (int j=0; j<n; j++) {
			if (b[n-1][j]==1) flag=false;
		}
		if (flag) ans=min(ans, cnt);
	}
	if (ans==INF) cout << -1;
	else cout << ans;

	return 0;
}
