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

vector<int> x;

bool cpr(const int& a, const int& b) {
	return x[a]<x[b];
}

int main() {
	init_code();

	int n, m, q;
	cin >> n >> m >> q;
	vector<intp> v(n);
	rep(i, n) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	x.resize(m);
	rep(i, m) cin >> x[i];
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		vector<int> can;
		for (int i=0; i<l; i++) {
			can.push_back(i);
		}
		for (int i=r+1; i<m; i++) {
			can.push_back(i);
		}
		sort(can.begin(), can.end(), cpr);
		priority_queue<int> pq;
		ll ans=0;
		int ptr=0;
		for (int i=0; i<can.size(); i++) {
			while (ptr<n && v[ptr].first<=x[can[i]]) {
				pq.push(v[ptr].second);
				ptr++;
			}
			if (!pq.empty()) {
				ans+=pq.top();
				pq.pop();
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
