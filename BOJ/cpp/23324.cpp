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

	int n, m, k;
	cin >> n >> m >> k;
	k--;
	vector<intp> edge(m);
	rep(i, m) {
		cin >> edge[i].first >> edge[i].second;
		edge[i].first--, edge[i].second--;
	}
	vector<int> siz(n, 1);
	vector<int> par(n);
	rep(i, n) par[i]=i;
	function<int(int)> find=[&](int x) {
		if (x==par[x]) return x;
		return par[x]=find(par[x]);
	};
	auto merge=[&](int a, int b) {
		a=find(a), b=find(b);
		par[a]=b;
		siz[b]+=siz[a];
	};
	rep(i, m) {
		if (i==k) continue;
		int a=edge[i].first;
		int b=edge[i].second;
		if (find(a)!=find(b)) merge(a, b);
	}
	int a=edge[k].first;
	int b=edge[k].second;
	if (find(a)==find(b)) {
		cout << 0;
	}
	else {
		a=find(a), b=find(b);
		cout << (ll)siz[a]*siz[b];
	}

	return 0;
}
