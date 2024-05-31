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

int main() {
	init_code();

	int n, x, y;
	cin >> n >> x >> y;
	x--, y--;
	vector<vector<int> > dis(n, vector<int>(n, INF));
	for (int i=0; i<n; i++) {
		dis[i][i]=0;
		for (int j=i+1; j<n; j++) {
			dis[i][j]=dis[i][j-1]+1;
		}
		for (int j=i-1; j>=0; j--) {
			dis[i][j]=dis[i][j+1]+1;
		}
	}
	vector<int> cnt(n, 0);
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			dis[i][j]=min(dis[i][j], min(dis[i][x]+1+dis[y][j], dis[j][x]+1+dis[x][i]));
			cnt[dis[i][j]]++;
		}
	}
	for (int i=1; i<n; i++) {
		cout << cnt[i] << '\n';
	}

	return 0;
}
