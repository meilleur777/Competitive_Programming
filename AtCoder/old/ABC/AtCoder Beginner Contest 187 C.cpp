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
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	set<string> st;
	rep(i, n) st.insert(s[i]);
	rep(i, n) {
		if (s[i].front()=='!') {
			if (st.find(s[i])!=st.end() && st.find(s[i].substr(1))!=st.end()) {
				cout << s[i].substr(1);
				return 0;
			}
		}
	}
	cout << "satisfiable";

	return 0;
}
