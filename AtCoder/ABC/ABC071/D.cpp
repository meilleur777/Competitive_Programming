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

const ll mod=1e9+7;
const int INF=0x3F3F3F3F;

string S[2];

ll solve(int now) {
	if (now==S[0].size()) return 1;
	ll ret=0;
	if (S[0][now-1]==S[1][now-1]) {
		if (S[0][now]==S[1][now]) {
			ret=solve(now+1)*2;
			ret%=mod;
		}
		else {
			ret=solve(now+2)*2;
			ret%=mod;
		}
	}
	else {
		if (S[0][now]==S[1][now]) {
			ret=solve(now+1);
		}
		else {
			ret=solve(now+2)*3;
			ret%=mod;
		}	
	}
	return ret;
}

int main() {
	init_code();

	int N;
	cin >> N;
	cin >> S[0] >> S[1];
	if (S[0][0]==S[1][0]) cout << 3*solve(1)%mod;
	else cout << 6*solve(2)%mod;

	return 0;
}
