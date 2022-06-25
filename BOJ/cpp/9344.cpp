#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;
typedef tuple<int, int, int> tp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, p, q;
		cin >> n >> m >> p >> q;
		p--, q--;

		priority_queue<tp, vector<tp>, greater<tp>> pq;
		rep(i, m) {
			int u, v, w;
			cin >> u >> v >> w;
			pq.push(make_tuple(w, u-1, v-1));
		}

		vector<int> par(n);
		rep(i, n) par[i]=i;
		function<int(int)> find=[&](int x) {
			if (x==par[x]) return x;
			return par[x]=find(par[x]);
		};
		auto merge=[&](int a, int b) {
			a=find(a);
			b=find(b);
			par[a]=b;
		};

		bool flag=false;
		while (!pq.empty()) {
			auto [w, u, v]=pq.top();
			pq.pop();
			if (find(u)==find(v)) continue;
			merge(u, v);
			if ((u==p && v==q) || (v==p && u==q)) flag=true;
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
