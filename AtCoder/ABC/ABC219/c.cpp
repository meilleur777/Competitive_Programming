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

	string x;
	cin >> x;
	int n;
	cin >> n;
	vector<pair<string, int>> s(n);
	vector<string> t(n);
	rep(i, n) {
		cin >> s[i].first;
		t[i]=s[i].first;
		s[i].second=i;
		for (auto& j:s[i].first) {
			for (int k=0; k<26; k++) {
				if (x[k]==j) {
					j=char(k+'a');
					break;
				}
			}
		}
	}
	sort(s.begin(), s.end());
	for (auto [a, b]:s) cout << t[b] << '\n';

	return 0;
}
