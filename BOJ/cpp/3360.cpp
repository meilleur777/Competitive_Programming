#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e6;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	ll ans=0;
	for (int i=0; i<=n; i+=3) {
		ans+=(n-i)/2+1;
	}
	cout << ans%mod;

	return 0;
}
