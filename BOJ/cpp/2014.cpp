#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int k, n;
	cin >> k >> n;
	vector<int> a(k);
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	ll mx=-1;
	rep(i, k) {
		cin >> a[i];
		pq.push(a[i]);
		mx=max(mx, (ll)a[i]);
	}
	int cnt=0;
	set<ll> st;
	while (!pq.empty()) {
		ll now=pq.top();
		pq.pop();
		cnt++;
		if (cnt==n) {
			cout << now;
			return 0;
		}
		if (now>INT_MAX) continue;
		rep(i, k) {
			ll nxt=a[i]*now;
			if (nxt>=mx && pq.size()>=n-cnt) {
				break;
			}
			if (st.find(nxt)==st.end()) {
				st.insert(nxt);
				pq.push(nxt);
				mx=max(mx, nxt);
			}
		}
	}

	return 0;
}
