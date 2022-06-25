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
	vector<ld> a(n);
	rep(i, n) cin >> a[i];
	int left=1, right=1e9;
	int ans;
	while (left<=right) {
		int mid=(left+right)/2;
		int cnt=0;
		for (int i=0; i<n; i++) {
			if (a[i]>mid) {
				cnt+=(a[i]-1)/mid;
			}
		}
		if (cnt<=k) {
			ans=mid;
			right=mid-1;
		}
		else {
			left=mid+1;
		}
	}
	cout << ans;

	return 0;
}
