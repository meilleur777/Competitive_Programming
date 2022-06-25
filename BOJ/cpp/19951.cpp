#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> p(n+1, 0), h(n);
	rep(i, n) cin >> h[i];
	rep(i, m) {
		int a, b, k;
		cin >> a >> b >> k;
		a--, b--;
		p[a]+=k;
		p[b+1]-=k;
	}
	rep(i, n) p[i+1]+=p[i];
	rep(i, n) cout << p[i]+h[i] << ' ';

	return 0;
}
