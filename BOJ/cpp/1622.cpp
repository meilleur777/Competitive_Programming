#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string a, b;
	while (getline(cin, a) && getline(cin, b)) {
		vector<int> acnt(26, 0), bcnt(26, 0);
		for (auto i:a) acnt[i-'a']++;
		for (auto i:b) bcnt[i-'a']++;
		string ans="";
		rep(i, 26) rep(j, min(acnt[i], bcnt[i])) ans+=char(i+'a');
		cout << ans << '\n';
	}

	return 0;
}
