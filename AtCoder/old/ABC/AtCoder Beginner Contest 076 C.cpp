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

	string s, t;
	cin >> s >> t;
	priority_queue<string, vector<string>, greater<string> > can;
	for (int i=0; i<=int(s.size()-t.size()); i++) {
		bool flag=true;
		for (int j=0; j<int(t.size()); j++) {
			if (s[i+j]=='?') continue;
			if (s[i+j]!=t[j]) {
				flag=false;
				break;
			}
		}
		if (flag) {
			can.push(s.substr(0, i)+t+string(s.begin()+i+(int)t.size(), s.end()));
		}
	}
	if (can.empty()) {
		cout << "UNRESTORABLE";
	}
	else {
		string ans=can.top();
		for (auto i:ans) {
			if (i=='?') cout << 'a';
			else cout << i;
		}
	}

	return 0;
}
