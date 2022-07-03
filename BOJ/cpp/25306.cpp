#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef unsigned long long ull;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ull a, b;
	cin >> a >> b;

	function<ull(ull)> sol=[](ull num) {
		ull ret=0;

		if (num%4==1 || num%4==2) ret+=1;

		for (int i=0; i<62; i++) {
			ull tmp=(1LL<<(i+1));

			if (num%tmp>=tmp/2 && (num%tmp)%2==0) {
				ret+=tmp/2;
			}
		}

		return ret;
	};
	cout << (sol(b)^sol(a-1));

	return 0;
}
