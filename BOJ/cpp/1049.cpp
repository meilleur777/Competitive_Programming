#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	int a=1e5, b=1e5;
	while (m--) {
		int c, d;
		cin >> c >> d;
		a=min(a, c);
		b=min(b, d);
	}
	int ans=INT_MAX;
	for (int cnt=0; cnt*6<n+6; cnt++) {
		ans=min(ans, a*cnt+max(0, n-cnt*6)*b);
	}
	cout << ans;

	return 0;
}
