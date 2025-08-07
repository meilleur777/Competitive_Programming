#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	int x, y, r;
	cin >> x >> y >> r;

	int a=0, b=0;
	for (int i=0; i<n; i++) {
		int t;
		cin >> t;

		if (x-r==t || x+r==t) b++;
		if (x-r<t && t<x+r) a++;
	}

	cout << a << ' ' << b;
	
	return 0;
}
