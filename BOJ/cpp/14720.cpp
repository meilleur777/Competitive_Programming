#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int now=0;
	int ans=0;
	rep(i, n) {
		int nxt;
		cin >> nxt;
		if (nxt==now) {
			ans++;
			now=(now+1)%3;
		}
	}
	cout << ans;

	return 0;
}
