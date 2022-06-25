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

	int m, n;
	cin >> m >> n;
	vector<pair<string, int>> s;
	for (int i=m; i<=n; i++) {
		string t=to_string(i);
		string tmp;
		for (auto j:t) {
			string k;
			switch (j-'0') {
				case 0: k="zero"; break;
				case 1: k="one"; break;
				case 2: k="two"; break;
				case 3: k="three"; break;
				case 4: k="four"; break;
				case 5: k="five"; break;
				case 6: k="six"; break;
				case 7: k="seven"; break;
				case 8: k="eight"; break;
				case 9: k="nine";
			}
			tmp+=k;
		}
		s.push_back({tmp, i});
	}
	sort(s.begin(), s.end());
	for (int i=1; i<=s.size(); i++) {
		cout << s[i-1].second;
		if (i%10==0) cout << '\n';
		else cout << ' ';
	}

	return 0;
}
