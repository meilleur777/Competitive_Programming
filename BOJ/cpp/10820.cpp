#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	while (getline(cin, s)) {
		vector<int> cnt(4, 0);
		for (auto c:s) {
			cnt[0]+=!!islower(c);
			cnt[1]+=!!isupper(c);
			cnt[2]+=!!isdigit(c);
			cnt[3]+=c==' ';
		}
		rep(i, 4) cout << cnt[i] << ' ';
		cout << '\n';
	}

	return 0;
}
