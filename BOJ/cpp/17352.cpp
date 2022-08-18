#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> par(n);
	rep(i, n) par[i]=i;
	function<int(int)> find=[&](int x) {
		if (par[x]==x) return x;
		return par[x]=find(par[x]);
	};
	function<void(int, int)> merge=[&](int a, int b) {
		a=find(a), b=find(b);
		if (a==b) return;
		par[a]=b;
	};
	rep(i, n-2) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		merge(a, b);
	}
	for (int i=1; i<n; i++) {
		if (find(0)!=find(i)) {
			cout << 1 << ' ' << i+1;
			return 0;
		}
	}

	return 0;
}
