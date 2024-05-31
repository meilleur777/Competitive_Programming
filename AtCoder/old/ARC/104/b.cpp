#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	vector<vector<int>> psum(4, vector<int>(n+1, 0));
	auto con=[&](char a) {
		if (a=='A') return 0;
		if (a=='T') return 1;
		if (a=='C') return 2;
		if (a=='G') return 3;
		return -1;
	};
	for (int i=1; i<=n; i++) {
		rep(j, 4) psum[j][i]+=psum[j][i-1];
		psum[con(s[i-1])][i]++;
	}
	int ans=0;
	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			vector<int> t(4);
			rep(k, 4) t[k]=psum[k][j]-psum[k][i-1];
			if (t[0]==t[1] && t[2]==t[3]) ans++;
		}
	}
	cout << ans;

	return 0;
}
