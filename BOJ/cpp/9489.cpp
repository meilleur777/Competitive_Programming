#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k;
	while (true) {
		cin >> n >> k;
		if (!n && !k) break;

		k--;
		vector<int> node;
		map<int, int> par;
		vector<int> cnt(1e6, 0);

		int a;
		int now;
		queue<int> q;

		cin >> a;
		a--;
		q.push(a);
		par[a]=-1;
		int memo=a;
		node.push_back(a);

		rep(i, n-1) {
			cin >> a;
			a--;
			node.push_back(a);
			if (memo+1<a) {
				now=q.front();
				q.pop();
			}
			par[a]=now;
			cnt[now]++;
			q.push(a);
			memo=a;
		}

		int ans=0;
		for (auto now:node) {
			if (now==k) continue;
			if (par[k]==-1 || par[now]==-1) continue;
			if (par[k]!=par[now] && par[par[k]]==par[par[now]]) ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}
