#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

ll mod=1e6+3;
ll n, s, e, t;
using mat=vector<vector<ll>>;

mat a, ans;
mat operator *(mat& p, mat& q) {
	mat ret(5*n, vector<ll>(5*n, 0));
	for (int i=0; i<n*5; i++) {
		for (int j=0; j<n*5; j++) {
			for (int k=0; k<n*5; k++) {
				ret[i][j]+=p[i][k]*q[k][j];
				ret[i][j]%=mod;
			}
		}
	}
	return ret;
}

void power(int k) {
	while (k) {
		if (k%2) ans=ans*a;
		a=a*a;
		k/=2;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> s >> e >> t;
	s--, e--;
	a=mat(n*5, vector<ll>(n*5, 0));
	ans=a;
	rep(i, n) {
		string edge;
		cin >> edge;
		for (int j=0; j<n; j++) {
			if (edge[j]-'0'==0) continue;
			a[i*5+4][j*5+4-(edge[j]-'0'-1)]=1;
		}
	}
	rep(i, n) {
		for (int j=0; j<4; j++) {
			a[i*5+j][i*5+j+1]=1;
		}
	}
	rep(i, n) ans[i*5+4][i*5+4]=1;

	power(t);
	cout << ans[s*5+4][e*5+4];

	return 0;
}
