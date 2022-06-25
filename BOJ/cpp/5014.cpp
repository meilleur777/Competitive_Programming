#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	queue<int> q;
	vector<int> vis(1e6+1, -1);
	q.push(s);
	vis[s]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		if (now==g) break;
		if (now+u<=f && vis[now+u]==-1) {
			vis[now+u]=vis[now]+1;
			q.push(now+u);
		}
		if (now-d>=1 && vis[now-d]==-1) {
			vis[now-d]=vis[now]+1;
			q.push(now-d);
		}
	}
	if (vis[g]==-1) cout << "use the stairs";
	else cout << vis[g];

	return 0;
}
