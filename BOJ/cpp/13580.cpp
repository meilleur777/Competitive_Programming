#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a==b || b==c || a==c || 2*max({a, b, c})==a+b+c) cout << "S";
	else cout << "N";

	return 0;
}
