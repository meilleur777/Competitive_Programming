#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i=0; i<20; i++) {
			if ((1<<i)&n) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
