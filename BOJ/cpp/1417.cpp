#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, one;
	cin >> n >> one;
	priority_queue<int> pq;
	rep(i, n-1) {
		int a;
		cin >> a;
		pq.push(a);
	}
	int ans=0;
	while (!pq.empty() && pq.top()>=one) {
		int t=pq.top()-1;
		pq.pop();
		if (t!=0) pq.push(t);
		ans++;
		one++;
	}
	cout << ans;

	return 0;
}
