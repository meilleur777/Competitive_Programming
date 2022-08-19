#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int c, k, p;
	cin >> c >> k >> p;
	ll ans=0;
	for (int i=1; i<=c; i++) {
		ans+=k*i+p*i*i;
	}
	cout << ans;

	return 0;
}
