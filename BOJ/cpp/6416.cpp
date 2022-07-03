#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int k=1;;
	while (true) {
		int cnt=0;
		map<int, int> mp;
		vector<int> par;

		function<int(int)> find=[&](int x) {
			if (x==par[x]) return x;
			return par[x]=find(par[x]);
		};
		function<void(int, int)> merge=[&](int a, int b) {
			a=mp[a], b=mp[b];
			a=find(a), b=find(b);
			par[a]=b;
		};

		int ecnt=0;
		while (true) {
			int u, v;
			cin >> u >> v;
			if (u<0 && v<0) {
				return 0;
			}
			if (!u && !v) break;
			ecnt++;

			if (mp.find(u)==mp.end()) {
				mp[u]=cnt;
				par.push_back(cnt);
				cnt++;
			}
			if (mp.find(v)==mp.end()) {
				mp[v]=cnt;
				par.push_back(cnt);
				cnt++;
			}
			merge(u, v);
		}

		bool flag=true;
		for (auto i:par) {
			if (find(i)!=find(0)) {
				flag=false;
				break;
			}
		}
		if (ecnt!=cnt-1) flag=false;
		if (!cnt) flag=true;
		cout << "Case " << k << " is ";
		if (!flag) {
			cout << "not ";
		}
		cout << "a tree.\n";
		k++;
	}

	return 0;
}
