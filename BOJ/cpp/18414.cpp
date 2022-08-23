#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	if (a<b) cout << b;
	else if (a>=b && a<=c) cout << a;
	else cout << c;

	return 0;
}
