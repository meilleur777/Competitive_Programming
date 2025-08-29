#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	long long n, t;
	cin >> n >> t;
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	int now=1;
	vector<bool> vis(n+1, false);
	while (!vis[now]) {
		vis[now]=true;
		now=a[now-1];
	}

	int cnt=0;
	while (vis[now]) {
		vis[now]=false;
		now=a[now-1];
		cnt++;
	}	

	int toCycle=0;
	int nxt=1;
	while (nxt!=now) {
		nxt=a[nxt-1];
		toCycle++;
	}

	if (t>toCycle) {
		t=toCycle+(t-toCycle)%cnt;
	}

	now=1;
	while (t--) {
		now=a[now-1];
	}

	cout << now;

	return 0;
}
