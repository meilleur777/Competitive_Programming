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

	int a, b, c;
	cin >> a >> b >> c;
	int tmp=max({a, b, c});
	int na=tmp-a, nb=tmp-b, nc=tmp-c;
	int ans=0;
	ans+=na/2+nb/2+nc/2;
	na%=2, nb%=2, nc%=2;
	switch (na+nb+nc) {
		case 0: cout << ans; break;
		case 1: cout << ans+2; break;
		case 2: cout << ans+1;
	}

	return 0;
}
