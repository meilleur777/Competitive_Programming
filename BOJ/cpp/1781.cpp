#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<intp> a(n);
	rep(i, n) {
		int b, c;
		cin >> b >> c;
		a[i]={b, c};
	}
	sort(a.begin(), a.end(), greater<intp>());
	priority_queue<int> pq;
	int now=a[0].first;
	int nxt=0;
	int ans=0;
	while (now>0) {
		while (nxt<n && a[nxt].first>=now) {
			pq.push(a[nxt].second);
			nxt++;
		}
		if (!pq.empty()) {
			ans+=pq.top();
			pq.pop();
		}
		now--;
	}
	cout << ans;

	return 0;
}
	