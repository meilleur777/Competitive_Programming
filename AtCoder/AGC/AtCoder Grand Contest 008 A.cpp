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

	int x, y;
	cin >> x >> y;
	int ans=2*INF;
	if (x<=y) ans=min(ans, y-x);
	if (-x<=y) ans=min(ans, y+x+1);
	if (y<=x) ans=min(ans, 2+x-y);
	if (y<=-x) ans=min(ans, 1-y-x);
	cout << ans;

	return 0;
}
