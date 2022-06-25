#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<ll> b(n);
	rep(i, n) cin >> b[i];
	map<ll, int> c;
	rep(i, n) {
		ll tmp=b[i];
		c[b[i]]=0;
		while (tmp%3==0) {
			c[b[i]]++;
			tmp/=3;
		}
	}
	sort(b.begin(), b.end(), [&](ll a, ll b) {
		if (c[a]==c[b]) return a<b;
		return c[a]>c[b];
	});
	ll now=b[0];
	cout << now << ' ';
	rep(i, n-1) {
		if (c.find(now*2)!=c.end()) now*=2;
		else if (now%3==0 && c.find(now/3)!=c.end()) now/=3;
		c.erase(now);
		cout << now << ' ';
	}	

	return 0;
}
