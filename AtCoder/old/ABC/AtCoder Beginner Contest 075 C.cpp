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

int find(int x) {
	if (x==par[x]) return x;
	return par[x]=find(par[x]);
}

void merge(int a, int b) {
	a=find(a), b=find(b);
	par[a]=b;
}

int main() {
	init_code();

	int n, m;
	cin >> n >> m;
	par.resize(n+1);
	vector<intp> v(m);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		v[i]={a, b};
	}
	int ans=0;
	for (int i=0; i<m; i++) {
		for (int j=1; j<=n; j++) par[j]=j;
		for (int j=0; j<m; j++) {
			if (i==j) continue;
			if (find(v[j].first)!=find(v[j].second)) {
				merge(v[j].first, v[j].second);
			}	
		}
		for (int j=2; j<=n; j++) {
			if (find(j)!=find(1)) {
				ans++;
				break;
			}
		}
	}
	cout << ans;

	return 0;
}
