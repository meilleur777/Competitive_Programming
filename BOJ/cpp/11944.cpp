#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	string sn=to_string(n);
	if (n*(int)sn.size()>m) {
		int t=m/(int)sn.size()*(int)sn.size();
		rep(i, t/(int)sn.size()) cout << sn;
		cout << sn.substr(0, m-t);
	}
	else {
		rep(i, n) cout << sn;
	}

	return 0;
}
