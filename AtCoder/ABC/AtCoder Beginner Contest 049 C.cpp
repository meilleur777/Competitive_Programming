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

	string s;
	cin >> s;
	vector<string> t({"dreameraser", "dreamerase", "dreamer", "dream", "eraser", "erase"});
	for (int i=0; i<(int)s.size(); i++) {
		bool pos=false;
		for (int j=0; j<t.size(); j++) {
			if (i+(int)t[j].size()<=s.size()) {
				if (string(s.begin()+i, s.begin()+i+(int)t[j].size())==t[j]) {
					pos=true;
					i+=(int)t[j].size()-1;
					break;
				}
			}
		}
		if (!pos) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}
