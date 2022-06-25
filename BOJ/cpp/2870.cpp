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

	int n;
	cin >> n;
	vector<string> ans;
	rep(i, n) {
		string s;
		cin >> s;
		for (int i=0; i<s.size(); i++) {
			int ptr=0;
			string t;
			while (isdigit(s[i+ptr])) {
				t.push_back(s[i+ptr]);
				ptr++;
			}
			i+=ptr;
			while (!t.empty() && t!="0" && t.front()=='0') t=t.substr(1);
			if (!t.empty()) ans.push_back(t);
		}
	}
	sort(ans.begin(), ans.end(), [](const string& a, const string& b) {
		if (a.size()==b.size()) return a<b;
		return a.size()<b.size();
	});
	for (auto i:ans) cout << i << '\n';

	return 0;
}
