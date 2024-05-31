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

	int n;
	cin >> n;
	int m=4e5;
	vector<int> par(m), siz(m, 1);
	rep(i, m) par[i]=i;
	function<int(int)> get=[&](int x) {
		if (x==par[x]) return x;
		return par[x]=get(par[x]);
	};
	auto mrg=[&](int a, int b) {
		a=get(a), b=get(b);
		par[a]=b;
		siz[b]+=siz[a];
	};
	vector<intp> edge(n);
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[i]={a, b};
		if (get(a)!=get(b)) mrg(a, b);
	}
	vector<bool> use(m, false);
	vector<int> cnt(m, 0);
	rep(i, n) {
		cnt[get(edge[i].first)]++;
	}
	int ans=0;
	rep(i, m) {
		int p=get(i);
		if (!use[p]) {
			use[p]=true;
			if (cnt[p]+1==siz[p]) ans+=siz[p]-1;
			else ans+=siz[p];
		}
	}
	cout << ans;

	return 0;
}
