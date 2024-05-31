#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string n;
	cin >> n;
	int ans=INF;
	for (int i=1; i<(1<<(int)n.size()); i++) {
		int tmp=0;
		int cnt=0;
		for (int j=0; j<(int)n.size(); j++) {
			if (i&(1<<j)) {
				tmp+=n[j]-'0';
			}
			else {
				cnt++;
			}
		}
		if (tmp%3==0) {
			ans=min(ans, cnt);
		}
	}
	if (ans==INF) cout << -1;
	else cout << ans;

	return 0;
}
