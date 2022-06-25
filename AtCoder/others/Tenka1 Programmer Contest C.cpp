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

int main() {
	init_code();

	ll N;
	cin >> N;
	for (ll h=1; h<=3500; h++) {
		for (ll w=1; w<=3500; w++) {
			if (4*h*w==N*w+N*h) continue;
			ll n=(N*h*w)/(4*h*w-N*w-N*h);
			if (n>0 && (N*h*w)%(4*h*w-N*w-N*h)==0) {
				cout << h << ' ' << n << ' ' << w;
				return 0;
			}
		}
	}

	return 0;
}
