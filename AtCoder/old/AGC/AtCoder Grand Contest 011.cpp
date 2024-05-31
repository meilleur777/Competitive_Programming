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

	int n, c, k;
	cin >> n >> c >> k;
	vector<int> t(n);
	rep(i, n) cin >> t[i];
	sort(t.begin(), t.end());
	int now=t[0];
	int cap=1;
	int ans=1;
	for (int i=1; i<n; i++) {
		if (now+k<t[i]) {
			ans++;
			cap=1;
			now=t[i];
		}
		else {
			if (cap>=c) {
				ans++;
				cap=1;
				now=t[i];
			}
			else {
				cap++;
			}
		}
	}	
	cout << ans;

	return 0;
}
