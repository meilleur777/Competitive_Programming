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
	rep(i, n) cin >> a[i];
	vector<ll> cnt(n+1, 0);
	ll sum=0;
	rep(i, n) {
		cnt[a[i]]++;
	}
	for (int i=1; i<=n; i++) {
		if (cnt[i]>1) {
			sum+=cnt[i]*(cnt[i]-1)/2;
		}
	}
	ll ans=0;
	for (int k=0; k<n; k++) {
		ll tmp=sum;
		ll now=cnt[a[k]];
		if (now>2) {
			tmp-=now*(now-1)/2;
			tmp+=(now-1)*(now-2)/2;
		}
		else if (now==2) {
			tmp-=now*(now-1)/2;
		}
		cout << tmp << '\n';
	}

	return 0;
}
