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

	int n;
	string s, t;
	cin >> n >> s >> t;
	int cnts=0, cntt=0;
	for (int i=0; i<n; i++) {
		cnts+=s[i]-'0';
		cntt+=t[i]-'0';
	}
	if (cnts<cntt || cnts%2!=cntt%2) {
		cout << -1;
		return 0;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	rep(i, n) {
		if (s[i]=='1') {
			pq.push(i);
		}
	}
	ll ans=0;
	for (int i=0; i<n; i++) {
		while (!pq.empty() && pq.top()<i) {
			int fir=pq.top();
			pq.pop();
			if (pq.empty()) {
				cout << -1;
				return 0;
			}
			int sec=pq.top();
			pq.pop();
			ans+=sec-fir;
		}
		if (t[i]=='1') {
			if (pq.empty()) {
				cout << -1;
				return 0;
			}
			else {
				ans+=pq.top()-i;
				pq.pop();
			}
		}
	}
	cout << ans;

	return 0;
}
