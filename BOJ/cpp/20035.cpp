#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	ll suma=0, sumb=0;
	rep(i, n) {
		cin >> a[i];
		a[i]*=1e9;
		suma+=a[i];
	}
	rep(i, m) {
		cin >> b[i];
		sumb+=b[i];
	}
	ll maxa=*max_element(a.begin(), a.end());
	ll maxb=*max_element(b.begin(), b.end());
	ll al, ah;
	for (int i=0; i<n; i++) if (maxa==a[i]) {
		al=i;
		break;
	}
	for (int i=n-1; i>=0; i--) if (maxa==a[i]) {
		ah=i;
		break;
	}
	cout << (suma+(m-1)*maxa)+sumb+b[0]*al+(n-ah-1)*b.back()+(ah-al)*maxb;
		
	return 0;
}
