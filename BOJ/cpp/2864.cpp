#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	
	int a, b;
	cin >> a >> b;

	int mx=0, mn=0;
	for (int i=0; i<8; i++)	 {
		int amn=a%10, amx=a%10;
		int bmn=b%10, bmx=b%10;

		if (amn==6) {
			amn=5;
		}
		if (bmn==6) {
			bmn=5;
		}
		if (amx==5) {
			amx=6;
		}
		if (bmx==5) {
			bmx=6;
		}

		mx+=pow(10, i)*(amx+bmx);
		mn+=pow(10, i)*(amn+bmn);

		a/=10;
		b/=10;
	}

	cout << mn << ' '  << mx << '\n';

	return 0;
}
