#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	map<char, int> mp;
	while (n--) {
		string s;
		cin >> s;
		mp[s.front()]++;
	}

	set<char> st;
	for (auto i:mp) {
		if (i.second>=5) {
			st.insert(i.first);
		}
	}
	if (st.empty()) cout << "PREDAJA";
	else {
		for (auto i:st) cout << i;
	}

	return 0;
}
