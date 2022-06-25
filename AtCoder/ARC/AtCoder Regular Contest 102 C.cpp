#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

ll power(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp;//%mod;
	if (b%2) return tmp*a;//%mod;
	return tmp;
}

int main() {
	init_code();

	int n, k;
	cin >> n >> k;
	if (k%2) {
		int tmp=n/k;
		cout << power(tmp, 3);
	}
	else {
		int a=n/(k/2);
		int b=n/k;
		a-=b;
		cout << power(a, 3)+power(b, 3);
	}

	return 0;
}
