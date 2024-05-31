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

int n, m;
vector<int> p;
vector<int> par;

int find(int x) {
	if (par[x]==x) return x;
	return par[x]=find(par[x]);
}

void merge(int a, int b) {
	a=find(a), b=find(b);
	par[a]=b;
}

int main() {
	init_code();

	cin >> n >> m;
	par.resize(n);
	rep(i, n) par[i]=i;
	p.resize(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		merge(x, y);
	}
	int ans=0;
	for (int i=0; i<n; i++) {
		if (find(i)==find(p[i])) {
			ans++;
		}
	}
	cout << ans;

	return 0;
}
