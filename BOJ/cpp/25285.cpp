#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		ld a, b;
		cin >> a >> b;
		if (a<=140) cout << 6;
		else if (a<146) cout << 5;
		else if (a<159) cout << 4;
		else if (a<161) {
			a/=100;
			ld tmp=(ld)b/(a*a);
			if (tmp>=16 && tmp<35) cout << 3;
			else cout << 4;
		}
		else {
			a/=100;
			ld tmp=(ld)b/(a*a);
			if (tmp>=20 && tmp<25) cout << 1;
			else if ((tmp>=18.5 && tmp<20) || (tmp>=25 && tmp<30)) cout << 2;
			else if ((tmp>=16 && tmp<18.5) || (tmp>=30 && tmp<35)) cout << 3;
			else cout << 4;
		}
		cout << '\n';
	}

	return 0;
}
