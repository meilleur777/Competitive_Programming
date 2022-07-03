#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll x, n;
	cin >> x >> n;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		x-=a*b;
	}
	if (x==0) cout << "Yes";
	else cout << "No";

	return 0;
}
