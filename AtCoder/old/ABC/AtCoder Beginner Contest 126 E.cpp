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
	par[b]=a;
}

int main() {
	init_code();

	int n, m;
	cin >> n >> m;
	par.resize(n+1);
	for (int i=1; i<=n; i++) par[i]=i;
	rep(i, m) {
		int x, y, z;
		cin >> x >> y >> z;
		if (find(x)==find(y)) continue;
		else {
			merge(x, y);
		}
	}
	int cnt=0;
	set<int> s;
	for (int i=1; i<=n; i++) {
		int tmp=find(i);
		if (s.count(tmp)==0) {
			s.insert(tmp);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
