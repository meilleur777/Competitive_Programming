#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a==0 && b==0 && c==0) break;

		if (b-a==c-b) {
			cout << "AP " << c+(c-b) << '\n';
		}
		else {
			cout << "GP " << c*(b/a) << '\n';
		}
	}

	return 0;
}
