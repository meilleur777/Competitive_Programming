#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	map<int, intp> mp;
	vector<intp> tree(n);
	rep(i, n) {
		int a, b, c;
		cin >> a >> b >> c;
		mp[a]={b, c};
		tree[i]={a, b};
	}

	int ans=n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				for (int l=0; l<n; l++) {
					priority_queue<int> pq;

					int need=2*(abs(tree[i].first-tree[j].first)+abs(tree[k].second-tree[l].second));
					int mny=min(tree[i].first, tree[j].first);
					int mxy=max(tree[i].first, tree[j].first);
					int mnx=min(tree[k].second, tree[l].second);
					int mxx=max(tree[k].second, tree[l].second);

					int cand=0;
					for (auto [p, q]:mp) {
						if (p<mny || p>mxy || q.first<mnx || q.first>mxx) {
							need-=q.second;
							cand++;
						}
						else pq.push(q.second);
					}
					while (!pq.empty() && need>0) {
						need-=pq.top();
						pq.pop();
						cand++;
					}
					if (need<=0) {
						ans=min(ans, cand);
					}

				}
			}
		}
	}
	cout << ans;

	return 0;
}
