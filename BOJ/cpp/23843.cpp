#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> t(n);
	rep(i, n) cin >> t[i];

	sort(t.begin(), t.end(), greater<int>());
	int left=0, right=(1<<15)*1e4;
	int ans=right;
	while (left<=right) {
		int mid=(left+right)/2;
		priority_queue<int, vector<int>, greater<int>> pq;
		rep(i, m) pq.push(0);
		rep(i, n) {
			int time=pq.top();
			pq.pop();
			pq.push(time+t[i]);
		}
		bool flag=false;
		while (!pq.empty()) {
			flag|=(pq.top()>mid);
			pq.pop();
		}
		if (!flag) {
			right=mid-1;
			ans=mid;
		}
		else {
			left=mid+1;
		}
	}
	cout << ans;

	return 0;
}
