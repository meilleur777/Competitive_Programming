#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n+1, 0);
	rep(i, n) {
		int q;
		cin >> q;
		a[i+1]=a[i]+q;
	}
	int m;
	cin >> m;
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << a[j]-a[i-1] << '\n';
	}

	return 0;
}
