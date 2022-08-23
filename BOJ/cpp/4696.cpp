#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cout << fixed;
	cout.precision(2);
	while (true) {
		string s;
		cin >> s;
		if (s=="0") break;
		ld a;
		a=stold(s);
		ld ans=0;
		rep(i, 5) ans+=pow(a, i);
		cout << ans << '\n';
	}

	return 0;
}
