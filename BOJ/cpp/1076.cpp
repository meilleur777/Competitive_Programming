#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

ll power(ll a, ll b) {
	ll ret=1;
	rep(i, b) ret*=a;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	map<string, ll> mp;
	vector<string> s({"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"});
	rep(i, (int)s.size()) {
		mp[s[i]]=i;
	}
	string a, b, c;
	cin >> a >> b >> c;
	cout << (mp[a]*10+mp[b])*power(10, mp[c]);

	return 0;
}
