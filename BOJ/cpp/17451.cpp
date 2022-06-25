#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	ll now=0;
	vector<ll> v(n);
	rep(i, n) cin >> v[i];
	for (int i=n-1; i>=0; i--) {
		if (now<=v[i]) now=v[i];
		else if (now%v[i]) now=now/v[i]*v[i]+v[i];
	}
	cout << now;

	return 0;
}
