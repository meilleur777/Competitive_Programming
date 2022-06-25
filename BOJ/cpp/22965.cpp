#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int cnt=0;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n-1) cnt+=a[i]>a[i+1];
	if (cnt==0) cout << 1;
	else if (cnt==1 && a[n-1]<=a[0]) cout << 2;
	else cout << 3;

	return 0;
}
