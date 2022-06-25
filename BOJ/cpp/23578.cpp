#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

struct cpr {
	bool operator()(pair<ll, ll>& a, pair<ll, ll>& b) {
		return a.first*(2*a.second+1)>b.first*(2*b.second+1);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cpr> pq;
	rep(i, n) {
		ll a;
		cin >> a;
		pq.push({a, 1});
	}
	if (n==1) {
		cout << 0;
		return 0;
	}
	if (n==2) {
		int tmp=0;
		while (!pq.empty()) {
			tmp+=pq.top().first;
			pq.pop();
		}
		cout << tmp;
		return 0;
	}
	int cnt=n;
	ll ans=0;
	while (true) {
		pair<ll, ll> tmp=pq.top();
		pq.pop();
		tmp.second++;
		pq.push(tmp);
		cnt++;
		if (cnt>=2*n-2) break;
		while (!pq.empty() && pq.top().second==n-1) {
			ans+=pq.top().first*pq.top().second*pq.top().second;
			pq.pop();
		}
	}
	while (!pq.empty()) {
		ans+=pq.top().first*pq.top().second*pq.top().second;
		pq.pop();
	}
	cout << ans;

	return 0;
}
