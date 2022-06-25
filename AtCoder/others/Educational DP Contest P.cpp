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

const ll mod=1e9+7;
const int INF=0x3F3F3F3F;

vector<bool> vis;
vector<vector<int> > child;
vector<vector<int> > edge;
vector<vector<ll> > cache;

void makeTree(int s) {
	vis[s]=true;
	for (auto i : edge[s]) {
		if (!vis[i]) {
			child[s].push_back(i);
			makeTree(i);
		}
	}
}

/*1->black, 0->white*/
ll solve(int now, int color) {
	if (child[now].empty()) {
		return 1;
	}
	ll& ret=cache[now][color];
	if (ret!=-1) return ret;
	ret=1;
	if (color==1) {
		for (auto i : child[now]) {
			ret*=solve(i, 0);
			ret%=mod;
		}
	}
	else if (color==0) {
		for (auto i : child[now]) {
			ret*=(solve(i, 1)+solve(i, 0))%mod;
			ret%=mod;
		}
	}
	return ret;
}

int main() {
	init_code();

	int N;
	cin >> N;
	vis=vector<bool>(N+1, false);
	edge=vector<vector<int> >(N+1);
	child=vector<vector<int> >(N+1);
	cache=vector<vector<ll> >(N+1, vector<ll>(2, -1));
	rep(i, N-1) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	makeTree(1);
	cout << (solve(1, 1)+solve(1, 0))%mod;

	return 0;
}
