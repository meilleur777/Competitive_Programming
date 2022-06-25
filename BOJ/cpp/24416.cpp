#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll> fib(n+1);
	fib[0]=0, fib[1]=1;
	for (int i=2; i<=n; i++) fib[i]=fib[i-1]+fib[i-2];
	cout << fib[n] << ' ' << n-2;

	return 0;
}
