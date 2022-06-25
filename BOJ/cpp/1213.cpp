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

	string s;
	cin >> s;
	vector<int> cnt(26, 0);
	for (auto i:s) {
		cnt[i-'A']++;
	}
	string ans;
	char memo='e';
	rep(i, 26) {
		if (cnt[i]%2) {
			if (memo!='e') {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			else {
				memo=char(i+'A');
			}
		}
		cnt[i]/=2;
		ans+=string(cnt[i], char(i+'A'));
	}
	cout << ans;
	if (memo!='e') cout << memo;
	reverse(ans.begin(), ans.end());
	cout << ans;

	return 0;
}
