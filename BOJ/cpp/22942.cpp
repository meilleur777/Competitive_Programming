#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<intp> v(n);
	rep(i, n) {
		int x, r;
		cin >> x >> r;
		v[i].first=x-r, v[i].second=x+r;
	}
	sort(v.begin(), v.end());
	rep(i, n-1) {
		if (v[i].second>=v[i+1].first && v[i].second<=v[i+1].second) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}
