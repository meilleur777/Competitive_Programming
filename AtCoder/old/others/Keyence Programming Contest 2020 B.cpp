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
	rep(i, n) {
		int x, l;
		cin >> x >> l;
		a[i]={x+l, x-l};
	}
	sort(a.begin(), a.end());
	int tmp=INT_MIN;
	int ans=0;
	for (int i=0; i<n; i++) {
		if (tmp<=a[i].second) {
			ans++;
			tmp=a[i].first;
		}
	}
	cout << ans;

	return 0;
}
