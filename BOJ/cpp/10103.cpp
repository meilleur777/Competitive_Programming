#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	int a=100, b=100;
	while (n--) {
		int aa, bb;
		cin >> aa >> bb;
		if (aa==bb) continue;
		if (aa<bb) {
			a=max(0, a-bb);
		}
		if (aa>bb) {
			b=max(0, b-aa);
		}
	} 
	
	cout << a << '\n' << b;

	return 0;
}
