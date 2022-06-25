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

	ll n, h;
	cin >> n >> h;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	ll str=*max_element(a.begin(), a.end());
	ll cnt=0;
	sort(b.rbegin(), b.rend());
	for (int i=0; i<n; i++) {
		if (b[i]>str) {
			cnt++;
			h-=b[i];
			if (h<=0) {
				cout << cnt;
				return 0;
			}
		}
		else {
			break;
		}
	}
	cnt+=(h+str-1)/str;
	cout << cnt;

	return 0;
}
