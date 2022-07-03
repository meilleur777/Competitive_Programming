#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	map<int, int> mp;
	rep(i, n) {
		int a;
		cin >> a;
		mp[a]=i+1;
	}
	rep(i, n) cout << mp[i+1] << '\n';

	return 0;
}
