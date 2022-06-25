#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	stack<char> sk;
	int ans=0;
	int now=0;
	for (int i=0; i<(int)s.size(); i++) {
		ans+=s[i]=='(';
		if (i!=(int)s.size()-1 && s.substr(i, 2)=="()") {
			ans--;
			i++;
			if (sk.empty()) continue;
			sk.push('l');
		}
		else if (s[i]=='(') {
			sk.push('(');
			now++;
		}
		else {
			int cnt=0;
			while (sk.top()=='l') {
				cnt++;
				sk.pop();
			}
			sk.pop();
			ans+=now*cnt;
			now--;
		}
	}
	cout << ans << '\n';

	return 0;
}
