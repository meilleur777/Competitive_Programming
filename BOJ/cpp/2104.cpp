#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<ll> a;
	a.push_back(-1);
	rep(i, n) {
		ll b;
		cin >> b;
		a.push_back(b);
	}
	a.push_back(-1);
	stack<ll> sk;
	sk.push(0);
	vector<ll> sum(n+3, 0);
	rep(i, n+2) {
		sum[i+1]+=sum[i]+a[i];
	}
	ll ans=0;
	for (int i=1; i<=n+1; i++) {
		while (sk.size()>1 && a[sk.top()]>a[i]) {
			ll mid=sk.top();
			sk.pop();
			ll left=sk.top();
			ans=max(ans, (sum[i]-sum[left+1])*a[mid]);
		}
		sk.push(i);
	}
	cout << ans;

	return 0;
}
