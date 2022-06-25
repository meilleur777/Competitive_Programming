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

vector<int> par, siz;

int find(int x) {
	if (x==par[x]) return x;
	return par[x]=find(par[x]);
}

void merge(int a, int b) {
	a=find(a), b=find(b);
	par[b]=a;
	siz[a]+=siz[b];
}

int main() {
	init_code();

	int n;
	cin >> n;
	vector<pair<int, intp> > edge;
	par.resize(n+1);
	siz=vector<int>(n+1, 1);
	for (int i=1; i<=n; i++) par[i]=i;
	rep(i, n-1) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({c, {a, b}});
	}
	sort(edge.begin(), edge.end());
	ll ans=0;
	for (int i=0; i<n-1; i++) {
		int a=edge[i].second.first;
		int b=edge[i].second.second;
		ll c=edge[i].first;
		ans+=c*siz[find(a)]*siz[find(b)];
		merge(a, b);
	}
	cout << ans;

	return 0;
}
