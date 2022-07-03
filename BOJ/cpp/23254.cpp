#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	rep(i, m) cin >> a[i];
	rep(i, m) cin >> b[i];
	int time=n*24;
	priority_queue<intp> pq;
	int ans=0;
	rep(i, m) {
		if (a[i]==100) continue;
		pq.push({min(100-a[i], b[i]), i});
	}
	while (time-- && !pq.empty()) {
		int num=pq.top().second;
		a[num]+=pq.top().first;
		pq.pop();
		pq.push({min(100-a[num], b[num]), num});
	}
	rep(i, m) {
		ans+=a[i];
	}
	cout << ans;

	return 0;
}
