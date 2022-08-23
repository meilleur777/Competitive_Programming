#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	cin >> s;
	int ans=10;
	for (int i=1; i<(int)s.size(); i++) {
		ans+=5+(s[i]!=s[i-1])*5;
	}
	cout << ans;

	return 0;
}
