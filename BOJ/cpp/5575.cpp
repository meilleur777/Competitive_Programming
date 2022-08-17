#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	rep(i, 3) {
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		int www=3600*d+60*e+f-3600*a-60*b-c;
		cout << www/3600 << ' ' << (www%3600)/60 << ' ' << (www%60) << '\n';
	}

	return 0;
}
