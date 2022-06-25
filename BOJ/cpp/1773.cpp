#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, c;
	cin >> n >> c;
	vector<bool> chk(c+1, false);
	rep(i, n) {
		int a;
		cin >> a;
		int now=a;
		while (true) {
			chk[now]=true;
			now+=a;
			if (now>c) break;
		}
	}
	int ans=0;
	rep(i, c+1) ans+=chk[i];
	cout << ans;

	return 0;
}
