#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	ll a, b, c;
	cin >> a >> b >> c;
	if (a==b && b==c) cout << 2;
	else if (2*max({a, b, c})*max({a, b, c})==a*a+b*b+c*c) cout << 1;
	else cout << 0;

	return 0;
}
