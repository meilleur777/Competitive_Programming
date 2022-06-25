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

const ll mod=998244353;
const int INF=0x3F3F3F3F;

int cnt=0;
vector<int> edge;
vector<bool> vis, chk;

void DFS(int now) {
	vis[now]=true;
	if (!vis[edge[now]]) {
		DFS(edge[now]);
	}
	else {
		if (!chk[edge[now]]) {
			cnt++;
		}
	}
	chk[now]=true;
}

int main() {
	init_code();

	int N;
	cin >> N;
	edge.resize(N+1);
	vis=chk=vector<bool>(N+1, false);
	rep(i, N) cin >> edge[i+1];
	for (int i=1; i<=N; i++) {
		if (!vis[i]) {
			DFS(i);
		}
	}
	ll ans=1;
	while (cnt--) {
		ans*=2;
		ans%=mod;
	}
	ans=(ans+mod-1)%mod;
	cout << ans;

	return 0;
}
