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
	vector<ll> a(n);
	ll sum=0;
	rep(i, n) {
		cin >> a[i];
		sum+=a[i];
	}
	sort(a.begin(), a.end(), greater<ll>());
	int ans=1;
	sum-=a[0];
	for (int i=1; i<n; i++) {
		sum-=a[i];
		if ((sum+a[i])*2>=a[i-1]) ans++;
		else break;
	}
	cout << ans;

	return 0;
}
