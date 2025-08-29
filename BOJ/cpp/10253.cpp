#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	if (a<b) swap(a, b);
	if (a%b==0) return b;
	else return gcd(b, a%b);
}

long long lcm(long long a, long long b) {
	return a/gcd(a, b)*b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	long long tc;
	cin >> tc;
	while (tc--) {
		long long a, b;
		cin >> a >> b;

		while (a!=1) {
			long long tmp=((b+a-1)/a);
			long long newa=tmp*a-b;
			long long newb=b*tmp;

			long long tmpGcd=gcd(newa, newb);
			a=newa/tmpGcd;
			b=newb/tmpGcd;
		}

		cout << b << '\n';
	}

	return 0;
}
