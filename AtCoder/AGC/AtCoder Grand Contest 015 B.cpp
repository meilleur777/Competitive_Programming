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

	string s;
	cin >> s;
	ll ans=0;
	int n=s.size();
	for (int i=0; i<n; i++) {
		if (s[i]=='U') {
			ans+=n-i-1;
			ans+=2*i;
		}
		else {
			ans+=2*(n-i-1);			
			ans+=i;
		}
	}
	cout << ans;

	return 0;
}
