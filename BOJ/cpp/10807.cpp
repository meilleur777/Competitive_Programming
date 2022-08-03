#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int v;
	cin >> v;

	int ans=0;
	rep(i, n) {
		ans+=a[i]==v;
	}
	cout << ans;

	return 0;
}
