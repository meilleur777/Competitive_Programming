#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int now=0;
	int ans=0;
	rep(i, 10) {
		int a, b;
		cin >> a >> b;
		now-=a;
		now+=b;
		ans=max(ans, now);
	}
	cout << ans;

	return 0;
}
