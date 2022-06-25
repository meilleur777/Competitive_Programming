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

int d;
vector<vector<int> > child;

int solve(int s) {
	int ret=0;
	if (child[s].empty()) return 1;
	if (child[s].size()==1 && child[s][0]==d) {
		return 1;
	}
	for (int i : child[s]) {
		if (i==d) continue;
		ret+=solve(i);
	}
	return ret;
}

int main() {
	init_code();

	int N;
	cin >> N;
	int root;
	child.resize(N);
	rep(i, N) {
		int x; 
		cin >> x;
		if (x==-1) root=i;
		else child[x].push_back(i);
	}
	cin >> d;
	if (d==root) cout << 0;
	else cout << solve(root);

	return 0;
}
