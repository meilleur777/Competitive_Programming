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
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	priority_queue<ll> pq;
	for (int i=0; i<n; i++) {
		if (a[i]>b[i]) {
			pq.push(a[i]-b[i]);
		}
	}
	int ans=0;
	ll now=0;
	for (int i=0; i<n; i++) {
		if (a[i]<b[i]) {
			while (!pq.empty() && now<b[i]-a[i]) {
				now+=pq.top();
				pq.pop();
				ans++;
			}
			if (now<b[i]-a[i]) {
				cout << -1;
				return 0;
			}
			now-=b[i]-a[i];
			ans++;
		}
	}
	cout << ans;

	return 0;
}
