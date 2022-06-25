#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k, p;
	cin >> n >> k >> p;
	int need=floor(log2(p));
	if (k-1<need) {
		cout << -1;
		return 0;
	}
	vector<int> ans(n+1, 0);
	set<int> st;

	ans[p]=k;
	st.insert(k);

	int t=p/2;
	for (int i=need; i>=1; i--) {
		ans[t]=i;
		t/=2;
		st.insert(i);
	}

	int bigger=k+1;
	function<void(int)> big=[&](int now) {
		if (now>n) return;
		ans[now]=bigger;
		st.insert(bigger);
		bigger++;
		big(now*2);
		big(now*2+1);
	};
	big(p*2), big(p*2+1);

	if (bigger>n+1) {
		cout << -1;
		return 0;
	}

	int nxt=1;
	for (int i=1; i<=n; i++) {
		while (st.find(nxt)!=st.end()) {
			nxt++;
		}
		if (ans[i]==0) {
			ans[i]=nxt;
			nxt++;
		}
		cout << ans[i] << '\n';
	}

	return 0;
}
