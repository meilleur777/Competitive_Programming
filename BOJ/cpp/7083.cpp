#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	int height=ceil(log2(n))+1;
	int siz=(1<<height);

	vector<int> inner(siz, n-1);

	vector<int> outer(siz, 0);
	for (int i=0; i<n; i++) {
		update(outer, 0, i, i, 0, n-1, i);
	}

	int ans=0;
	bool fail=false;
	while (m--) {
		int p, q;
		cin >> p >> q;
		p--;
		q--;

		if (fail) continue;

		if (p>q) swap(p, q);

		if (getMin(inner, 0, p, 0, n-1)>=q) {
			update(inner, 0, p, q, 0, n-1, q);
			ans++;
		}
		else {
			int pPar=getPar(p);
			int qPar=getPar(q);

			if (pPar==qPar) {
				update(outer, 0, p, q, 0, n-1, p);
				ans++;
			}
			else {
				fail=true;
			}
		}
	}

	cout << ans;

	return 0;
}
