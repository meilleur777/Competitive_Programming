#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	int ans=1e9;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (a<=b) ans=min(ans, b);
	}
	if (ans==1e9) cout << -1;
	else cout << ans;

	return 0;
}
