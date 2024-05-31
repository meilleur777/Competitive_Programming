#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n);
	vector<int> ind(n, 0);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
		ind[b]++;
	}
	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> pq;
	rep(i, n) {
		if (ind[i]==0) pq.push(i);
	}
	while (!pq.empty()) {
		int now=pq.top();
		pq.pop();
		ans.push_back(now);
		for (auto i:edge[now]) {
			ind[i]--;
			if (ind[i]==0) pq.push(i);
		}
	}
	if (ans.size()!=n) cout << -1;
	else for (auto i:ans) cout << i+1 << ' ';

	return 0;
}
