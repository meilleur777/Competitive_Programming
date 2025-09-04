#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];

	function<int(int, const vector<int> &)> lisSum=[&](int start, const vector<int> &v) {
		vector<int> res;

		for (int i=start; i<start+n; i++) {
			int tgt=i%n;

			if (res.empty() || res.back()<v[tgt]) {
				res.push_back(v[tgt]);
			}
			else {
				int index=lower_bound(res.begin(), res.end(), v[tgt])-res.begin();
				res[index]=v[tgt];
			}
		}

		return (int)res.size();
	};

	int yj=0;
	int hg=0;

	for (int i=0; i<n; i++) {
		yj=max(yj, lisSum(i, a));
		hg=max(hg, lisSum(i, b));
	}

	if (yj>hg) cout << "YJ";
	else if (yj==hg) cout << "Both";
	else cout << "HG";
	cout << " Win!";

	return 0;
}
