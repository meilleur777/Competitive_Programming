#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int a, b, c, m;
	cin >> a >> b >> c >> m;
	int now=0;
	int ans=0;
	for (int i=0; i<24; i++) {
		if (now+a<=m) {
			ans+=b;
			now+=a;
		}
		else {
			now=max(0, now-c);
		}
	}
	cout << ans;

	return 0;
}
