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

vector<vector<vector<ld>>> dp(100, vector<vector<ld>>(100, vector<ld>(100, -1.0)));

ld sol(int a, int b, int c) {
	if (a==100 || b==100 || c==100) {
		return 0.0;
	}
	ld& ret=dp[a][b][c];
	if (ret!=-1.0) return ret;
	ret=0.0;
	ret+=(1.0+sol(a+1, b, c))*a/(a+b+c);
	ret+=(1.0+sol(a, b+1, c))*b/(a+b+c);
	ret+=(1.0+sol(a, b, c+1))*c/(a+b+c);
	return ret;
}

int main() {
	init_code();
	cout << fixed;
	cout.precision(10);

	int a, b, c;
	cin >> a >> b >> c;
	cout << sol(a, b, c);

	return 0;
}
