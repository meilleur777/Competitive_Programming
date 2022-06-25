#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const ll mod=1e9+7;

typedef vector<vector<ll>> mat;

mat operator*(mat a, mat b) {
	int n=a.size();
	mat c(n, vector<ll>(n, 0));
	rep(i, n) rep(j, n) rep(k, n) {
		c[i][k]+=a[i][j]*b[j][k]%mod;
		c[i][k]%=mod;
	}
	return c;
}

mat a={
    {0, 1, 0, 0, 1, 0 ,0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 1, 0},
    {1, 1, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 1, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll d;
	cin >> d;
	mat idn(8, vector<ll>(8, 0));
	rep(i, 8) rep(j, 8) if (i==j) idn[i][j]=1;
	function<mat(ll)> power=[&](ll now) {
		if (now==0) return idn;
		if (now==1) return a;
		mat tmp=power(now/2);
		tmp=tmp*tmp;
		if (now%2) return tmp*a;
		return tmp;
	};
	mat res=power(d);
	cout << res[0][0];

	return 0;
}
