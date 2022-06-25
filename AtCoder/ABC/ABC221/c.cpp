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

	string n;
	cin >> n;
	ll ans=-1;
	sort(n.begin(), n.end());
	do {
		for (int i=0; i<n.size()-1; i++) {
			string a=n.substr(0, i+1);
			string b=n.substr(i+1);
			ll c=stoll(a);
			ll d=stoll(b);
			if (c==0 || d==0) continue;
			ans=max(ans, c*d);
		}
	} while (next_permutation(n.begin(), n.end()));
	cout << ans;

	return 0;
}
