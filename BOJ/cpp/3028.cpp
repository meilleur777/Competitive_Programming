#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	vector<bool> w(3, false);
	w[0]=true;
	for (auto i:s) {
		if (i=='A') swap(w[0], w[1]);
		else if (i=='B') swap(w[1], w[2]);
		else swap(w[0], w[2]);
	}
	rep(i, 3) {
		if (w[i]) {
			cout << i+1;
			return 0;
		}
	}

	return 0;
}
