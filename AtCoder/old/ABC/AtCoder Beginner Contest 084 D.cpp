#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

vector<int> num(1e5+1, 0);
vector<bool> isprime(1e5+1, true);

void sieve() {
	isprime[0]=isprime[1]=false;
	for (int i=2; i*i<=1e5; i++) {
		for (int j=i*2; j<=1e5; j+=i) {
			isprime[j]=false;
		}
	}
}

int main() {
	init_code();

	sieve();
	for (int i=1; i<=1e5; i++) {
		num[i]+=num[i-1];
		if (isprime[i] && isprime[(i+1)/2]) {
			num[i]++;
		}
	}
	int q;
	cin >> q;
	rep(i, q) {
		int l, r;
		cin >> l >> r;
		cout << num[r]-num[l-1] << '\n';
	}

	return 0;
}
