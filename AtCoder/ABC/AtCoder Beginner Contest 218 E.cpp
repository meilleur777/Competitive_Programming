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
	else return par[x]=find(par[x]);
}

void merge(int a, int b) {
	a=find(a), b=find(b);
	par[a]=b;
}

int main() {
	init_code();

	int n, m;
	cin >> n >> m;
	par.resize(n);
	rep(i, n) par[i]=i;
	vector<pair<int, intp> > edge(m);
	ll sum=0;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[i]={c, {a, b}};
		sum+=c;
	}
	sort(edge.begin(), edge.end());
	ll cos=0;
	ll tmp=0;
	for (auto i:edge) {
		int a=i.second.first;
		int b=i.second.second;
		int c=i.first;
		if (find(a)!=find(b)) {
			merge(a, b);
			cos+=c;
		}
		else {
			if (c<0) {
				tmp+=c;
			}
		}
	}
	cout << max(0LL, sum-cos-tmp);

	return 0;
}
