#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll a;
	ll b=0;
	while (cin >> a) {
		b+=a;
	}
	cout << b+1;

	return 0;
}
