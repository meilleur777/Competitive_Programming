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

vector<vector<int> > child;

int solve(int s) {
	int ret=0;
	vector<int> can;
	for (auto i : child[s]) {
		can.push_back(solve(i));
	}
	sort(can.begin(), can.end(), greater<int>());
	for (int i=0; i<can.size(); i++) {
		ret=max(ret, can[i]+i+1);
	}
	return ret;
}

int main() {
	init_code();

	int N;
	cin >> N;
	int t;
	cin >> t;
	child=vector<vector<int> >(N+1);
	rep(i, N-1) {
		int x;
		cin >> x;
		child[x].push_back(i+1);
	}
	cout << solve(0);

	return 0;
}
