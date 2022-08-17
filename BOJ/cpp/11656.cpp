#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	cin >> s;
	set<string> st;
	for (int i=0; i<(int)s.size(); i++) {
		st.insert(s.substr(i));
	}
	for (auto i:st) cout << i << '\n';

	return 0;
}
