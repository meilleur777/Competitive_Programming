#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

vector<bool> ispri(55556, true);
vector<int> primes;

void sieve() {
	ispri[0]=ispri[1]=false;
	for (int i=2; i<=55555; i++) {
		if (ispri[i] && i%5==1) {
			primes.push_back(i);
		}
		for (int j=i*2; j<=55555; j+=i) {
			ispri[j]=false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	sieve();
	int n;
	cin >> n;
	rep(i, n) {
		cout << primes[i] << ' ';
	}

	return 0;
}
