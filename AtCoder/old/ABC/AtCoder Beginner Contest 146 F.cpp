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

	int n, m;
	string s;
	cin >> n >> m >> s;
	queue<int> q;
	q.push(0);
	vector<int> pi(n+1, -1);
	deque<int> dq;
	for (int i=1; i<=n; i++) {
		if (s[i]!='1') dq.push_back(i);
	}
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		if (now==n) {
			vector<int> ans;
			int tmp=now;
			while (true) {
				ans.push_back(tmp-pi[tmp]);
				tmp=pi[tmp];
				if (tmp==0) break;
			}
			reverse(ans.begin(), ans.end());
			for (auto i:ans) cout << i << ' ';
			return 0;
		}
		for (auto& nxt:dq) {
			if (now+m<nxt) break;
			if (pi[nxt]==-1) {
				pi[nxt]=now;
				q.push(nxt);
			}
		}
		while (!dq.empty() && dq.front()<now+m) dq.pop_front();
	}
	cout << -1;

	return 0;
}
