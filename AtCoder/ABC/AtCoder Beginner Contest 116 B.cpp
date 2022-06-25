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

	int s;
	cin >> s;
	bool chk[1000001]={false};
	chk[s]=true;
	int ans=1;
	while (true) {
		if (s&1) {
			s=3*s+1;	
		}
		else {
			s=s/2;
		}
		ans++;
		if (chk[s]==true) {
			cout << ans;
			return 0;
		}
		else chk[s]=true;
	}

	return 0;
}
