#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int x;
	string s;
	cin >> x >> s;
	stack<char> sk;
	rep(i, (int)s.size()) {
		if (sk.empty()) sk.push(s[i]);
		else if (sk.top()!=s[i]) sk.pop();
		else if (i+1<(int)s.size() && sk.top()!=s[i+1]) {
			sk.pop();
			swap(s[i], s[i+1]);
		}
		else sk.push(s[i]);
		if (sk.size()>x) {
			cout << i;
			return 0;
		}
	}
	cout << (int)s.size();

	return 0;
}
