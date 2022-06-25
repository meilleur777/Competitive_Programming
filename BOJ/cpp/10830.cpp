#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

typedef vector<vector<int>> mat;

mat operator*(mat a, mat b) {
	int n=a.size();
	mat c(n, vector<int>(n, 0));
	rep(i, n) rep(j, n) rep(k, n) {
		c[i][k]+=a[i][j]*b[j][k];
		c[i][k]%=(int)1e3;
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n, b;
	cin >> n >> b;
	mat a(n, vector<int>(n));
	mat idn=a;
	rep(i, n) rep(j, n) {
		cin >> a[i][j];
		a[i][j]%=(int)1e3;
	}
	rep(i, n) rep(j, n) {
		if (i==j) idn[i][j]=1;
		else idn[i][j]=0;
	}
	function<mat(ll)> power=[&](ll now) {
		if (now==0) return idn;
		if (now==1) return a;
		mat tmp=power(now/2);
		tmp=tmp*tmp;
		if (now%2) return tmp*a;
		return tmp;
	};
	mat res=power(b);
	rep(i, n) {
		rep(j, n) {
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
