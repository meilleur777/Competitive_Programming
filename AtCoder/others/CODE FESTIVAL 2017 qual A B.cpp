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

	int n, m, k;
	cin >> n >> m >> k;
	for (int r=0; r<=n; r++) {
		for (int c=0; c<=m; c++) {
			if (n*c+m*r-2*c*r==k) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";

	return 0;
}
