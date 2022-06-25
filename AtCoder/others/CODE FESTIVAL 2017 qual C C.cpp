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
	int ans=0;
	int lo=0, hi=s.size()-1;
	while (lo<hi) {
		if (s[lo]==s[hi]) {
			lo++;
			hi--;
		}
		else {
			if (s[lo]=='x') {
				lo++;
				ans++;
			}
			else if (s[hi]=='x') {
				hi--;
				ans++;
			}
			else {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;

	return 0;
}
