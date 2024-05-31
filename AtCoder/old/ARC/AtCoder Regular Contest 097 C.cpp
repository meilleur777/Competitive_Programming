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
	int k;
	cin >> s >> k;
	set<string> st;
	for (int i=0; i<s.size(); i++) {
		for (int j=1; i+j<=s.size() && j<=k; j++) {
			string t=s.substr(i, j);
			st.insert(t);
		}
	}
	int cnt=0;
	for (auto i:st) {
		cnt++;
		if (cnt==k) {
			cout << i;
			break;
		}
	}

	return 0;
}
