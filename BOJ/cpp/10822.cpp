#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	int now=0;
	int ans=0;
	for (auto c:s) {
		if (c==',') {
			ans+=now;
			now=0;
		}
		else {
			now*=10;
			now+=c-'0';
		}
	}
	ans+=now;
	cout << ans;

	return 0;
}
