#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t=3;
	while (t--) {
		string s;
		cin >> s;
		int now=1;
		int ans=1;
		for (int i=1; i<8; i++) {
			if (s[i]==s[i-1]) {
				now++;
				ans=max(ans, now);
			}
			else {
				now=1;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
