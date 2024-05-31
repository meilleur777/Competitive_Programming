#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

int N;
int cntPrimeFactor[1001]={0};

void getPrimeFactor(int x) {
	for (int i=2; i*i<=x; i++) {
		while (x%i==0) {
			x/=i;
			cntPrimeFactor[i]++;
		}
	}
	if (x!=1) {
		cntPrimeFactor[x]++;
	}
}

int main() {
	init_code();

	cin >> N;
	for (int i=2; i<=N; i++) {
		getPrimeFactor(i);
	}
	ll ans=1;
	for (int i=2; i<=N; i++) {
		if (cntPrimeFactor[i]!=0) {
			ans*=cntPrimeFactor[i]+1;
			ans%=mod;
		}
	}
	cout << ans;

	return 0;
}
