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
	ll ans=stoll(s);
	for (int i=1; i<(1<<(int(s.size())-1)); i++) {
		int las=0;
		for (int j=0; j<s.size()-1; j++) {
			if (i&(1<<j)) {
				ans+=stoll(s.substr(las, j-las+1));
				las=j+1;
			}	
		}
		ans+=stoll(s.substr(las, s.size()-las));
	}
	cout << ans;

	return 0;
}
