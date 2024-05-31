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
	vector<intp> a(n);
	rep(i, n) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());
	int ans=0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			int c=a[j].second-a[i].second;
			int d=a[j].first-a[i].first;
			if (d>=c && c>=-d) ans++;
		} 
	}
	cout << ans;

	return 0;
}
