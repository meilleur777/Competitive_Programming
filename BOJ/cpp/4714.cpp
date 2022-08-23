#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cout << fixed;
	cout.precision(2);
	while (true) {
		ld a;
		cin >> a;
		if (a<0) break;
		cout << "Objects weighing " << a << " on Earth will weigh " << a*0.167 << " on the moon.\n";
	}

	return 0;
}
