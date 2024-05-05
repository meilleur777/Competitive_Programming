#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	while (c--) {
		b++;
		if (b==60) {
			b=0;
			a++;
			if (a==24) a=0;
		}
	}	
	cout << a << ' ' << b;

	return 0;
}
