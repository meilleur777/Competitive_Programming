#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	cin >> s;

	ll ans=0;
	rep(i, (int)s.size()) {
		rotate(s.begin(), s.begin()+1, s.end());
		ans+=stoll(s);
	}
	cout << ans;

	return 0;
}
