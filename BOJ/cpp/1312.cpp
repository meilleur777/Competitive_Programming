#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int a, b, n;
	cin >> a >> b >> n;
	for (int i=0; i<n; i++) {
		a%=b;
		a*=10;
	}
	cout << a/b;
	
	return 0;
}
