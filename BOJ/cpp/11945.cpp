#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	rep(i, n) reverse(s[i].begin(), s[i].end());
	rep(i, n) cout << s[i] << '\n';

	return 0;
}
	