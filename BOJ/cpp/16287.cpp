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

	int w, n;
	cin >> w >> n;
	vector<int> a(n);
	vector<bool> dp(w+1, false);
	rep(i, n) cin >> a[i];
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (w-a[i]-a[j]<=0) continue;
			if (dp[w-a[i]-a[j]]) {
				cout << "YES";
				return 0;
			}
		}
		for (int j=0; j<i; j++) {
			if (a[i]+a[j]<w) dp[a[i]+a[j]]=true;
		}
	}
	cout << "NO";

	return 0;
}
