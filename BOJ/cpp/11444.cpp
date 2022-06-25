#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;

const ll mod=1e9+7;

mat operator *(const mat& a, const mat& b) {
	int n=a.size();
	mat tmp(n, vector<ll>(n, 0));
	rep(i, n) rep(j, n) rep(k, n) {
		tmp[i][j]+=a[i][k]*b[j][k];
		tmp[i][j]%=mod;
	}
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n;
	cin >> n;
	mat a={{1, 1}, {1, 0}};
	mat bas={{1, 0}, {0, 1}};
	function<mat(ll)> power=[&](ll b) {
		if (b==0) return bas;
		if (b==1) return a;
		mat tmp=power(b/2);
		tmp=tmp*tmp;
		if (b%2) return tmp*a;
		return tmp;
	};
	mat ans=power(n);
	cout << ans[0][1];

	return 0;
}
