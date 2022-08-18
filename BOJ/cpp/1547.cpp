#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	vector<int> v({1, 0, 0});
	int m;
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		int t=v[a];
		v[a]=v[b];
		v[b]=t;
	}
	rep(i, 3) {
		if (v[i]) cout << i+1;
	}

	return 0;
}

