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

ll pow(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=pow(a, b/2);
	tmp=tmp*tmp;
	if (b%2) return tmp*a;
	return tmp;
}

int main() {
	init_code();

	ll x, y, a, b;
	cin >> x >> y >> a >> b;
	ll ans=0;
	while ((ld)a*x<=LLONG_MAX && a*x<=x+b && a*x<y) {
		x*=a;
		ans++;
	}
	ans+=(y-x-1)/b;
	cout << ans;

	return 0;
}
