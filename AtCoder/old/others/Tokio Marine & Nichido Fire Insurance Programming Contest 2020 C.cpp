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

	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	for (int j=0; j<k; j++) {
		vector<ll> b(n+1, 0);
		for (int i=0; i<n; i++) {
			int lo=max(0LL, i-a[i]);
			int hi=min((ll)n, a[i]+i+1);
			b[lo]++;
			b[hi]--;
		}	
		a[0]=b[0];
		for (int i=1; i<n; i++) {
			b[i]+=b[i-1];
			a[i]=b[i];
		}
		if (*min_element(a.begin(), a.end())==n) {
			rep(i, n) cout << n << ' ';
			return 0;
		}
	}
	rep(i, n) cout << a[i] << ' ';

	return 0;
}
