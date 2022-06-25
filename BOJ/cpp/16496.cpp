#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<string> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end(), [&](string& p, string& q) { return p+q>q+p; });
	if (a[0][0]=='0') cout << 0;
	else for (auto i:a) cout << i;

	return 0;
}
