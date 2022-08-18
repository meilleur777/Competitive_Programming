#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

const ll mod=1e9+7;

int t, n, d;	

using mat=vector<vector<ll>>;
mat operator *(const mat& a, const mat& b) {
	mat ret(n, vector<ll>(n, 0));
	rep(i, n) rep(j, n) rep(k, n) {
		ret[i][j]+=a[i][k]*b[k][j];
		ret[i][j]%=mod;
	}
	return ret;
}

mat ans;
mat base;

void power(ll b) {
	while (b) {
		if (b%2) ans=ans*base;
		b/=2;
		base=base*base;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> t >> n >> d;
	vector<vector<vector<ll>>> edge(t, vector<vector<ll>>(n, vector<ll>(n, 0)));
	rep(i, t) {
		int m;
		cin >> m;
		while (m--) {
			int a, b, c;
			cin >> a >> b >> c;
			edge[i][a-1][b-1]=c;
		}
	}

	ans=mat(n, vector<ll>(n, 0));
	rep(i, n) ans[i][i]=1;

	if (d==0) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cout << ans[i][j] << ' ' ;
			}
			cout << '\n';
		}
		return 0;
	}

	for (int i=0; i<min(d, t); i++) {
		ans=ans*edge[i];
	}
	base=ans;

	if (d>t) {
		power(d/t-1);
		for (int i=0; i<d%t; i++) {
			ans=ans*edge[i];
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << ans[i][j] << ' ' ;
		}
		cout << '\n';
	}

	return 0;
}
