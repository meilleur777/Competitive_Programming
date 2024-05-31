#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	string s, t;
	cin >> n >> s >> t;
	vector<int> a, b;
	rep(i, n) {
		if (s[i]=='0') a.push_back(i);
		if (t[i]=='0') b.push_back(i);
	}
	if (a.size()!=b.size()) {
		cout << -1;
		return 0;
	}
	int ans=0;
	rep(i, a.size()) {
		ans+=(a[i]!=b[i]);
	}
	cout << ans;

	return 0;
}
