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


int N, K;
vector<bool> vis;
vector<vector<int> > child;
vector<vector<int> > edge;

void makeTree(int s) {
	vis[s]=true;
	for (auto i : edge[s]) {
		if (!vis[i]) {
			child[s].push_back(i);
			makeTree(i);
		}
	}
}

ll solve(int now, int from) {
	int allow;
	if (from==0) {
		allow=K-1;
	}
	else {
		allow=K-2;
	}
	if (allow<child[now].size()) return 0;
	ll ret=1;
	for (auto i : child[now]) {
		ret*=allow;
		ret%=mod;
		allow--;
	}
	for (auto i : child[now]) {
		ret*=solve(i, now);
		ret%=mod;
	}
	return ret;
}

int main() {
	init_code();

	cin >> N >> K;
	vis=vector<bool>(N+1, false);
	edge.resize(N+1);
	child.resize(N+1);
	rep(i, N) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	makeTree(1);	
	cout << K*solve(1, 0)%mod;

	return 0;
}
