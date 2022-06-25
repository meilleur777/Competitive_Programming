#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll a=(n+2)/3;
	ll b=(n-1)/2;
	ll siz=b-a+1;
	ll ans=-1;
	if (siz%2==0) {
		ll as=(3*a-n+2)/2, ae=(3*(b-1)-n+2)/2;
		ll bs=(3*(a+1)-n+2)/2, be=(3*b-n+2)/2;
		siz/=2;
		ans=siz*(as+ae)/2+siz*(bs+be)/2;
	}
	else {
		ll as=(3*a-n+2)/2, ae=(3*b-n+2)/2;
		ll bs=(3*(a+1)-n+2)/2, be=(3*(b-1)-n+2)/2;
		siz/=2;
		ans=(siz+1)*(as+ae)/2+siz*(bs+be)/2;
	}
	cout << ans;

	return 0;
}
