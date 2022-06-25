#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k, a, b;
	cin >> n >> k >> a >> b;
	vector<int> v(n, k);
	int ans=1;
	int now=0;
	while (true) {
		bool flag=true;
		for (int i=now; i<now+a; i++) v[i]+=b;
		rep(i, n) {
			v[i]--;
			if (v[i]==0) {
				flag=false;
				break;
			}
		}
		if (!flag) break;
		now=(now+a)%n;
		ans++;
	}
	cout << ans;

	return 0;
}
