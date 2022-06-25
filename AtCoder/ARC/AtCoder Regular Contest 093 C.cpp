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

int main() {
	init_code();

	int n;
	cin >> n;
	vector<int> a(n+2);
	rep(i, n) cin >> a[i+1];
	a[0]=a[n+1]=0;
	ll sum=0;
	for (int i=0; i<=n; i++) {
		sum+=abs(a[i]-a[i+1]);
	}
	for (int i=1; i<=n; i++) {
		ll tmp=sum-(abs(a[i-1]-a[i])+abs(a[i]-a[i+1]))+abs(a[i-1]-a[i+1]);
		cout << tmp << '\n';
	}

	return 0;
}
