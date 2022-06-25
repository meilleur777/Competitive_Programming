#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<intp> cor(n+2);
		rep(i, n+2) {
			int x, y;
			cin >> x >> y;
			cor[i]=make_pair(x, y);
		}
		vector<bool> vis(n+2, false);
		vis[0]=true;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int now=q.front();
			int x=cor[now].first;
			int y=cor[now].second;
			q.pop();
			for (int nxt=0; nxt<n+2; nxt++) {
				if (vis[nxt]) continue;
				if (abs(cor[nxt].first-x)+abs(cor[nxt].second-y)>1000) continue;
				q.push(nxt);
				vis[nxt]=true;
			}
		}
		if (vis[n+1]) cout << "happy\n";
		else cout << "sad\n";
	}

	return 0;
}
