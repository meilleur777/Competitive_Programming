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

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string atc("atcoder");
		if (atc<s) {
			cout << 0 << '\n';
		}
		else if (s==string(s.size(), 'a')) {
			cout << -1 << '\n';
		}
		else {
			int her=-1;
			for (int i=1; i<(int)s.size(); i++) {
				if (s[i]>'a') {
					her=i;
					break;
				}
			}
			if (s[her]>'t') cout << her-1 << '\n';
			else cout << her << '\n';
		}
	}

	return 0;
}
