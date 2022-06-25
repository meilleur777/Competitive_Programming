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

vector<int> C;
vector<vector<int> > edge;
vector<bool> isGood; 
vector<bool> vis;
vector<bool> color(1e5+1, false);

void solve(int s) {
	vis[s]=true;
	bool flag=false;
	if (color[C[s]]==true) {
		flag=true;
		isGood[s]=false;
	}
	color[C[s]]=true;
	for (auto i : edge[s]) {
		if (vis[i]) continue;
		solve(i);
	}
	color[C[s]]=flag;
}

int main() {
	init_code();

	int N;
	cin >> N;
	C.resize(N+1);
	vis=vector<bool>(N+1, false);
	isGood=vector<bool>(N+1, true);
	edge.resize(N+1);
	rep(i, N) cin >> C[i+1];
	rep(i, N-1) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	solve(1);
	for (int i=1; i<=N; i++) {
		if (isGood[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}
