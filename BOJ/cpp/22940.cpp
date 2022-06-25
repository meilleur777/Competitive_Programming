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

vector<vector<ll> > a;

ll gcd(ll a, ll b) {
	if (a%b==0) return b;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {	
	return a*b/gcd(a, b);
}

void sol(ll n) {
	if (n==(ll)a.size()) return;
	for (ll j=n+1; j<(ll)a.size(); j++) {
		ll t=a[n][n];
		ll k=a[j][n];
		if (t==0 || k==0) continue;
		ll l=lcm(t, k);
		vector<ll> tmp=a[n];
		for (auto& o:tmp) {
			o*=l/t;
		}
		for (ll o=n; o<(ll)a[0].size(); o++) {
			a[j][o]*=l/k;
			a[j][o]-=tmp[o];
		}
	}
	sol(n+1);
}

int main() {
	init_code();

	ll n;
	cin >> n;
	a=vector<vector<ll> >(n, vector<ll>(n+1));
	rep(i, n) rep(j, n+1) cin >> a[i][j];
	sol(0);
	vector<ll> x(n);
	for (ll i=n-1; i>=0; i--) {
		if (a[i][i]==0) {
			x[i]=0;
			continue;
		}
		x[i]=a[i][n]/a[i][i];
		for (ll j=i-1; j>=0; j--) {
			a[j][n]-=x[i]*a[j][i];
		}
	}
	for (auto i:x) cout << i << ' ';

	return 0;
}
