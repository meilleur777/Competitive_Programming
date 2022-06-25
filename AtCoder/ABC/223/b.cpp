#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	string mn(1, 'z'+1);
	string mx(1, 'a'-1);
	int n=s.size();
	rep(i, n) {
		mn=min(mn, s);
		mx=max(mx, s);
		rotate(s.begin(), s.begin()+1, s.end());
	}
	cout << mn << '\n' << mx;

	return 0;
}
