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

int main() {
	init_code();

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> par(N+1, -1);
		rep(i, N-1) {
			int c, d;
			cin >> c >> d;
			par[d]=c;
		}
		int a, b;
		cin >> a >> b;
		vector<bool> vis(N+1, false);
		while (true) {
			vis[a]=true;
			a=par[a];
			if (a==-1) break;
		}
		while (vis[b]==false) {
			b=par[b];
		}
		cout << b << '\n';
	}

	return 0;
}
