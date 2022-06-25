#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

vector<bool> ispri(51, true);
vector<int> primes;

void sieve() {
	ispri[0]=ispri[1]=false;
	for (int i=2; i<=51; i++) {
		if (ispri[i]) primes.push_back(i);
		for (int j=i*2; j<=51; j+=i) {
			ispri[j]=false;
		}
	}
}

int gcd(int a, int b) {
	if (a%b==0) return b;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	sieve();
	int n;
	cin >> n;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	ll ans=0x3f3f3f3f3f3f3f3f;
	for (int i=0; i<(1<<(int)primes.size()); i++) {
		ll y=1;
		for (int j=0; j<(int)primes.size(); j++) {
			if (i&(1<<j)) y*=primes[j];
		}
		bool ok=true;
		for (int j=0; j<n; j++) {
			if (gcd(x[j], y)==1) {
				ok=false;
				break;
			}
		}
		if (ok) {
			ans=min(ans, y);
		}
	}
	cout << ans;

	return 0;
}
