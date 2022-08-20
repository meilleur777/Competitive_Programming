#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	set<int> st;
	queue<intp> q;
	rep(i, n) {
		int a;
		cin >> a;
		st.insert(a);
		q.push({a, 0});
	}

	ll ans=0;
	while (!q.empty() && k) {
		int now=q.front().first;
		int cost=q.front().second;
		q.pop();
		if (k && st.find(now+1)==st.end()) {
			k--;
			st.insert(now+1);
			q.push({now+1, cost+1});
			ans+=cost+1;
		}
		if (k && st.find(now-1)==st.end()) {
			k--;
			st.insert(now-1);
			q.push({now-1, cost+1});
			ans+=cost+1;
		}
	}
	cout << ans;

	return 0;
}
