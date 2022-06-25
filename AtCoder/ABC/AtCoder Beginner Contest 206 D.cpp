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

vector<vector<int>> edge(2e5+1);
vector<bool> vis(2e5+1, false);

int dfs(int now) {
	vis[now]=true;
	int ret=1;
	for (auto i:edge[now]) {
		if (!vis[i]) {
			ret+=dfs(i);
		}
	}
	return ret;
}

int main() {
	init_code();

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	for (int i=0; i<n/2; i++) {
		if (a[i]!=a[n-i-1]) {
			edge[a[i]].push_back(a[n-i-1]);
			edge[a[n-i-1]].push_back(a[i]);
		}
	}
	int ans=0;	
	rep(i, 2e5+1) {
		if (!vis[i]) {
			ans+=dfs(i)-1;
		}
	}
	cout << ans;

	return 0;
}
