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

int n;
vector<int> a;

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

	cin >> n;
	a.resize(n);
	rep(i, n) cin >> a[i];
	int cnt=0;
	rep(i, n) cnt+=a[i]%2;
	cnt=n-cnt;
	cout << power(3, n)-power(2, cnt);

	return 0;
}
