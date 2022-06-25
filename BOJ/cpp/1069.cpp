#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << fixed;
	cout.precision(14);

	ll x, y, d, t;
	cin >> x >> y >> d >> t;
	ld dis=sqrt((ld)x*x+y*y);
	ld ans=dis;	
	ll tmp=(ll)dis/d;
	dis-=tmp*d;
	if (tmp==0) {
		ans=min(ans, min((ld)2*t, t+d-dis));
	}
	else {
		ans=min(ans, min({tmp*t+dis, (ld)(tmp+1)*t, (ld)(tmp+1)*t+(tmp+1)*d-dis}));
	}
	cout << ans;

	return 0;
}
