#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!a && !b && !c) break;
		if (2*max({a, b, c})>=a+b+c) cout << "Invalid";
		else if (a==b && b==c) cout << "Equilateral";
		else if ((a==b && a!=c) || (b==c && a!=b) || (a==c && b!=c)) cout << "Isosceles";
		else cout << "Scalene";
		cout << '\n';
	}

	return 0;
}
