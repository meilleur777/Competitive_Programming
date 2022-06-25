#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	string s;
	ll k;
	cin >> s >> k;
	vector<ll> t;
	ll row=1;
	for (int i=0; i<s.size()-1; i++) {
		if (s[i]==s[i+1]) {
			row++;
		}
		else {
			t.push_back(row);
			row=1;
		}
	}
	t.push_back(row);
	if (row==s.size()) {
		cout << (ll)s.size()*k/2;
		return 0;
	}
	ll a=0, b=0;
	for (auto i:t) {
		// cout << i << ' ';
		a+=i/2;
	}
	if (s.front()==s.back()) {
		b-=t.back()/2+t.front()/2;
		b+=(t.back()+t.front())/2;
	}
	// cout << b << ' ' << a << '\n';
	ll ans=(k-1)*b+a*k;
	cout << ans;

	return 0;
}

/*
aaaaa
3

a
1
*/