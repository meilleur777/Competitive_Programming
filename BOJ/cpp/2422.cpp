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

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> fbd(n, vector<bool>(n, false));
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		fbd[b][a]=true;
		fbd[a][b]=true;
	}
	int ans=0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				if (!fbd[i][j] && !fbd[i][k] && !fbd[j][k]) {
					ans++;
				}
			}
		}
	}
	cout << ans;

	return 0;
}
