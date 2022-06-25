#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<intp>> edge(n);
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}
	int p, q;
	cin >> p >> q;
	vector<int> hom(p), con(q);
	rep(i, p) {
		cin >> hom[i];
		hom[i]--;
	}
	rep(i, q) {
		cin >> con[i];
		con[i]--;
	}
	int INF=1e9+100000;
	vector<int> dis(n, INF);
	priority_queue<intp, vector<intp>, greater<intp>> pq;
	rep(i, q) {
		dis[con[i]]=0;
		pq.push({dis[con[i]], con[i]});
	}
	while (!pq.empty()) {
		int now=pq.top().second;
		int use=pq.top().first;
		pq.pop();
		if (use>dis[now]) continue;
		for (auto nxt:edge[now]) {
			if (dis[nxt.first]>nxt.second+use) {
				dis[nxt.first]=nxt.second+use;
				pq.push({dis[nxt.first], nxt.first});	
			}
		}
	}
	int ansd=INF;
	int ansn=6000;
	rep(i, p) {
		if (dis[hom[i]]==ansd) ansn=min(ansn, hom[i]);
		else if (dis[hom[i]]<ansd) {
			ansd=dis[hom[i]];
			ansn=hom[i];
		}
	}
	cout << ansn+1;

	return 0;
}
