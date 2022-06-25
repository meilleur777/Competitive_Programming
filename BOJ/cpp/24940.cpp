#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	auto get=[&](ll q, ll p) {
		if (q*p<0) return q*p;
		return 0LL;
	};
	vector<ll> psum(n+1, 0);
	rep(i, n) {
		psum[i+1]=psum[i]+a[i];
	}
	vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MAX));
	function<ll(int, int)> sol=[&](int left, int right) {
		ll& ret=dp[left][right];
		if (ret!=LLONG_MAX) {
			return ret;
		}
		if (left==right) return 0LL;
		if (left+1==right) return get(a[left], a[right]);
		for (int i=left; i<right; i++) {
			ret=min(ret, sol(left, i)+sol(i+1, right)+get(psum[i+1]-psum[left], psum[right+1]-psum[i+1]));
		}
		return ret;
	};
	cout << sol(0, n-1);

	return 0;
}
