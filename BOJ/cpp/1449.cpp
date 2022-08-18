#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	sort(a.begin(), a.end());

	int now=-1;
	int ans=0;
	for (int i=0; i<n; i++) {
		if (now<a[i]) {
			ans++;
			now=a[i]+l-1;
		}
	}
	cout << ans;

	return 0;
}
