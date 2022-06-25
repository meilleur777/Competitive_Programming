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
	vector<bool> fro(n, false), to(n, false);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (a>b) swap(a, b);
		if (a==0) {
			fro[b]=true;
		}
		else if (b==n-1) {
			to[a]=true;
		}
	}
	for (int i=1; i<n-1; i++) {
		if (fro[i] && to[i]) {
			cout << "POSSIBLE";
			return 0;
		}
	}
	cout << "IMPOSSIBLE";

	return 0;
}
