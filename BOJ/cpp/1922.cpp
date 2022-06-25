#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int par[1001];

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

	int N, M;
	cin >> N >> M;
	vector<pair<int, intp> > edge;
	rep(i, N) par[i+1]=i+1;
	rep(i, M) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({c, {a, b}});
	}
	sort(edge.begin(), edge.end());
	int ans=0;
	for (auto i : edge) {
		int a=i.second.first;
		int b=i.second.second;
		int c=i.first;
		if (find(a)!=find(b)) {
			merge(a, b);
			ans+=c;
		}
	}
	cout << ans;

	return 0;
}
