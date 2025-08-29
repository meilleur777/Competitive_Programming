#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	vector<long double> mem(n+1, 1.0);
	mem[0]=0;

	for (int i=2; i<=n; i++) {
		for (int j=1; j<=6; j++) {
			if (i-j<0) break;

			mem[i]+=(mem[i-j])/6;
		}
	}

	cout << fixed;
	cout.precision(10);
	cout << mem[n];

	return 0;
}
