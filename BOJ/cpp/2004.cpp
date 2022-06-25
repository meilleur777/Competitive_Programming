#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
typedef long long ll;

ll count(ll x, ll y) {
	ll result = 0;
	while (x > 0) { x /= y; result += x; }
	return result;
}

int main() {
	ll n, m; scanf("%lld %lld", &n, &m);
	printf("%lld\n", MIN(count(n, 2) - count(m, 2) - count(n - m, 2),
						 count(n, 5) - count(m, 5) - count(n - m, 5)));
}

