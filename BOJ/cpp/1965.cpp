#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, a;
	cin >> n;
	vector<int> v;
	v.push_back(-1);
	rep(i, n) {
		cin >> a;
		if (a>v.back()) v.push_back(a);
		else v[lower_bound(v.begin(), v.end(), a)-v.begin()]=a;
	}
	cout << v.size()-1;

	return 0;
}
