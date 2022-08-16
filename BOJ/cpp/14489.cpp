#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	ll a, b, c;
	cin >> a >> b >> c;
	if (a+b>=2*c) cout << a+b-2*c;
	else cout << a+b;

	return 0;
}
