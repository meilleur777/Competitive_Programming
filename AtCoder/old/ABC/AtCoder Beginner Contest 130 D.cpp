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

	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	int left=0, right=0;
	ll sum=0, ans=0;
	for (int left=0; left<n; left++) {
		while (right<n && sum<k) {
			sum+=a[right];
			right++;
		}
		if (sum>=k) ans+=n-right+1;
		sum-=a[left];	
	}
	cout << ans;

	return 0;
}
