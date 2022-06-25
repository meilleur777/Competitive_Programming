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

	ll N, M;
	cin >> N >> M;
	ll left=1, right=2e12;
	ll ans=0;
	while (left<=right) {
		bool pos;
		ll mid=(left+right)/2;
		if (N>=mid && M>=2*mid) pos=true;
		else if (M<2*mid) pos=false;
		else {
			if (M-(mid-N)*2<2*mid) pos=false;
			else pos=true;
		}
		if (pos==true) {
			ans=max(ans, mid);
			left=mid+1;
		}
		else {
			right=mid-1;
		}
	}	
	cout << ans;

	return 0;
}
