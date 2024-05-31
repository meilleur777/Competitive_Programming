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
	
vector<bool> ispri(1e7, true);

void sieve() {
	ispri[0]=ispri[1]=false;
	for (int i=2; i*i<=1e7; i++) {
		for (int j=i*2; j<=1e7; j+=i) {
			ispri[j]=false;
		}
	}
}

int main() {	
	init_code();

	sieve();
	int x;
	cin >> x;
	for (int i=x; i<=1e7; i++) {
		if (ispri[i]) {
			cout << i;
			return 0;
		}
	}

	return 0;
}
