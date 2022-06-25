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

	ll h;
	cin >> h;
	ll num=1;
	ll ans=0;
	while (true) {
		if (h==1) {
			ans+=num;
			cout << ans;
			break;
		}
		else {
			h/=2;
			ans+=num;
			num*=2;
		}
	}

	return 0;
}
