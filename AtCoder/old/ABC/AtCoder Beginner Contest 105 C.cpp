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

	ll n;
	cin >> n;
	if (n==0) {
		cout << 0;
		return 0;
	}
	ll tmp=1;
	string ans;
	while (n) {
		if (n%(2*llabs(tmp))) {
			ans+='1';
			n-=tmp;
		}
		else {
			ans+='0';
		}
		tmp*=-2;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;

	return 0;
}
