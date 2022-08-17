#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<intp> a(n);
	rep(i, n) cin >> a[i].first >> a[i].second;
	int ans=2e9+1;
	for (int i=1; i<(1<<n); i++) {
		int st=1, bt=0;
		for (int j=0; j<n; j++) {
			if (i&(1<<j)) {
				st*=a[j].first;
				bt+=a[j].second;
			}
		}
		ans=min(ans, abs(st-bt));
	}
	cout << ans;

	return 0;
}
