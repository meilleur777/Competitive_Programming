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

bool chk(int a) {
	string t=to_string(a);
	for (int i=0; i<(int)t.size(); i++) {
		if (t[i]!=t[(int)t.size()-i-1]) return false;
	}
	return true;
}

int main() {
	init_code();

	int a, b;
	cin >> a >> b;
	int ans=0;
	for (int i=a; i<=b; i++) {
		if (chk(i)) ans++;
	}
	cout << ans;

	return 0;
}
