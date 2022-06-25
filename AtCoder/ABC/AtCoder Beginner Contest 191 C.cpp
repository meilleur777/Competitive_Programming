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

	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	int ans=0;
	rep(i, h-1) rep(j, w-1) {
		int cnt=0;
		for (int k=0; k<2; k++) {
			for (int l=0; l<2; l++) {
				if (s[i+k][j+l]=='#') cnt++;
			}
		}
		if (cnt==1 || cnt==3) ans++;
	}
	cout << ans;

	return 0;
}
