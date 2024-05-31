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

vector<int> cache;
vector<vector<int> > edge;

int solve(int s) {
	if (edge[s].empty()) {
		return 0;
	}	
	int& ret=cache[s];
	if (ret!=-1) return ret;
	ret=0;
	for (auto i : edge[s]) {
		ret=max(ret, solve(i)+1);
	}
	return ret;
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	edge.resize(N+1);
	cache=vector<int>(N+1, -1);
	rep(i, M) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
	}
	int res=-1;
	for (int i=1; i<=N; i++) {
		res=max(res, solve(i));
	}
	cout << res;

	return 0;
}
