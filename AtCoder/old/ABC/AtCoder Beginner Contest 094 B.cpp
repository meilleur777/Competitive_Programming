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

	int n, m, x;
	cin >> n >> m >> x;
	vector<int> a(m);
	rep(i, m) cin >> a[i];
	int c1=0, c2=0;
	for (int i=0; i<m; i++) {
		if (a[i]<x) c1++;
		if (a[i]>x) c2++;
	}
	cout << min(c1, c2);

	return 0;
}
