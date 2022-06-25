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

	int g, p; 
	cin >> g >> p;
	par.resize(g+1);
	rep(i, g) par[i+1]=i+1;
	vector<int> a(p);
	rep(i, p) {
		cin >> a[i];
	}
	int ans=0;
	rep(i, p) {
		int tmp=find(a[i]);
		if (tmp==0) break;
		merge(tmp-1, tmp);
		ans++;
	}
	cout << ans;

	return 0;
}
