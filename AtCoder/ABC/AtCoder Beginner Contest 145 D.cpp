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

ll power(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp%mod;
	if (b%2) return tmp*a%mod;
	return tmp;
}

int ncr(int n, int r) {
	ll res=1;
	for (int i=1; i<=r; i++) {
		res*=(n-i+1);
		res%=mod;
		res*=power(i, mod-2);
		res%=mod;
	}
	return (int)res;
}

int main() {
	init_code();

	int x, y;
	cin >> x >> y;
	if ((x+y)%3) {
		cout << 0;
		return 0;
	}
	int m=(2*x-y)/3;
	int n=(y-m)/2;
	if (m<0 || n<0) {
		cout << 0;
		return 0;
	}
	cout << ncr(n+m, n);

	return 0;
}
