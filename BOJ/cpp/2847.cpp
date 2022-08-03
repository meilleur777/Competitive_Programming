#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	int ans=0;
	for (int i=n-2; i>=0; i--) {
		ans+=max(a[i]-(a[i+1]-1), 0);
		a[i]=min(a[i], a[i+1]-1);
	}
	cout << ans;

	return 0;
}
