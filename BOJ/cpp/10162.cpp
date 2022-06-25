#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	if (t%10) cout << -1;
	else {
		t/=10;
		cout << t/30 << ' ';
		t%=30;
		cout << t/6 << ' ';
		t%=6;
		cout << t;
	}

	return 0;
}
