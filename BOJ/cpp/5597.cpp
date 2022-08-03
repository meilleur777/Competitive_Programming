#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
		
	vector<bool> chk(30, false);
	rep(i, 28) {
		int a;
		cin >> a;
		chk[a-1]=true;
	}
	rep(i, 30) {
		if (!chk[i]) cout << i+1 << '\n';
	}

	return 0;
}
