#include <stdio.h>

typedef long long ll; 

ll Euc(ll a, ll b) {
	if (!(a % b)) return b;
	else return Euc(b, a % b);
}

int main() {
	ll a, b; scanf("%lld %lld", &a, &b);
	ll res = Euc(a, b);
	for (ll i = 0; i < res; i++) printf("1");
}

