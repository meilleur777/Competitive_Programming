#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int n, m;
	cin >> n >> m;
	vector<intp> v(n);
	rep(i, n) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	priority_queue<int> pq;
	int ptr=0;
	ll ans=0;
	for (int i=m-1; i>=0; i--) {
		while (ptr<n && v[ptr].first+i<=m) {
			pq.push(v[ptr].second);
			ptr++;
		}
		if (!pq.empty()) {
			ans+=pq.top();
			pq.pop();
		}
	}
	cout << ans;

	return 0;
}
