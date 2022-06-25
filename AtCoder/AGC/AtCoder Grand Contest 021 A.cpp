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

	string n;
	cin >> n;
	reverse(n.begin(), n.end());
	int ans=0;
	for (int i=0; i<n.size()-1; i++) {
		if (n[i]<'0') {
			n[i+1]--;
			n[i]='9';
		}
		if (n[i]!='9') {
			n[i+1]--;
		}
		ans+=9;
	}
	ans+=n.back()-'0';
	cout << ans;

	return 0;
}
