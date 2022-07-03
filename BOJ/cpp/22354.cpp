#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	if (n<3) {
		cout << 0;
		return 0;
	}

	char now=s[0];
	int mx=a[0];
	vector<int> b;
	for (int i=1; i<n; i++) {
		if (now!=s[i]) {
			b.push_back(mx);
			now=s[i];
			mx=a[i];
		}
		else {
			mx=max(mx, a[i]);
		}
	}
	b.push_back(mx);
	ll ans=0;
	priority_queue<int> pq;
	for (int i=1; i<(int)b.size()-1; i++) {
		pq.push(b[i]);
	}
	int cnt=((int)b.size()-1)/2;
	while (cnt--) {
		ans+=pq.top();
		pq.pop();
	}
	cout << ans;

	return 0;
}
