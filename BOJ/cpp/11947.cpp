#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;

		string strn=to_string(n);
		int dig=(int)strn.size();
		long long locMax=1;
		while (dig--) {
			locMax*=10;
		}

		long long nines=locMax-1;
		locMax/=2;

		if (n<locMax) {
			cout << n*(nines-n) << '\n';
		}
		else {
			cout << locMax*(nines-locMax) << '\n';
		}
	}

	return 0;
}
