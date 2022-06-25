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

vector<int> par;
vector<int> siz;

int find(int x) {
	if (x==par[x]) return x;
	return par[x]=find(par[x]);
}

void merge(int a, int b) {
	a=find(a), b=find(b);
	par[a]=b;
	siz[b]+=siz[a];
}

int main() {
	init_code();

	int n, m, k;
	cin >> n >> m >> k;
	vector<intp> edge;
	par.resize(n+1);
	rep(i, n) par[i+1]=i+1;
	siz=vector<int>(n+1, 1);
	vector<vector<int> > fri(n+1), blo(n+1);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		fri[a].push_back(b);
		fri[b].push_back(a);
		edge.push_back({a, b});
	}
	rep(i, k) {
		int a, b;
		cin >> a >> b;
		blo[a].push_back(b);
		blo[b].push_back(a);
	}
	for (auto [a, b]:edge) {
		if (find(a)!=find(b)) {
			merge(a, b);
		}
	}
	for (int i=1; i<=n; i++) {
		int ipa=find(i);
		int com=siz[ipa];
		int tmp=0;
		for (auto j:blo[i]) {
			if (ipa==find(j)) {
				tmp++;
			}
		}
		cout << com-1-tmp-fri[i].size() << ' ';
	}

	return 0;
}
