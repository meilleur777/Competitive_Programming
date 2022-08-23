#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());

	function<void(vector<int>)> sol=[&](vector<int> now) {
		if ((int)now.size()==m) {
			for (auto i:now) cout << i << ' ';
			cout << '\n';
			return;
		}
		for (int i=0; i<n; i++) {
			vector<int> t=now;
			t.push_back(a[i]);
			sol(t);
		}
	};	
	vector<int> q;
	sol(q);

	return 0;
}
