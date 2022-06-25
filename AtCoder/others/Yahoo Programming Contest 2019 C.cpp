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

	ll k, a, b;
	cin >> k >> a >> b;
	if (b-a>1) {
		if (k<a-1) {
			cout << k+1;
		}
		else {
			k-=a-1;
			if (k%2) {
				cout << a+(b-a)*(k/2)+1;
			}	
			else {
				cout << a+(b-a)*(k/2);
			}
		}
	}
	else {
		cout << 1+k;
	}

	return 0;
}
