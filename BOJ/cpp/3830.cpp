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
const ll INF=0x3F3F3F3F3F3F3F3F;

vector<int> par;
vector<ll> dis;

int find(int x) {
	if (x==par[x]) return x;
	int tmp=find(par[x]);
	dis[x]+=dis[par[x]];
	return par[x]=tmp;
}

void merge(int a, int b, int w) {
	int ap=find(a), bp=find(b);
	par[ap]=bp;
	dis[ap]=dis[b]-dis[a]-w;
}	

int main() {
	init_code();

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n==0) break;
		par=vector<int>(n);
		dis=vector<ll>(n, 0);
		rep(i, n) par[i]=i;
		rep(i, m) {
			char c;
			cin >> c;
			if (c=='!') {
				int a, b, w;
				cin >> a >> b >> w;
				a--, b--;
				if (find(a)!=find(b)) {
					merge(a, b, w);
				}
			}
			else {
				int a, b;
				cin >> a >> b;
				a--, b--;
				if (find(a)!=find(b)) {
					cout << "UNKNOWN\n";
				}
				else {
					cout << dis[b]-dis[a] << '\n';
				}
			}
		}
	}

	return 0;
}
