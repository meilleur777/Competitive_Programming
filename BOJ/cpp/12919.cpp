#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s, t;
	cin >> s >> t;
	function<void(string)> sol=[&](string q) {
		if (q==s) {
			cout << 1;
			exit(0);
		}
		if ((int)q.size()<(int)s.size()) return;

		if (q.back()=='A') {
			sol(q.substr(0, (int)q.size()-1));
		}
		if (q.front()=='B') {
			string qq=q.substr(1);
			reverse(qq.begin(), qq.end());
			sol(qq);
		}
	};
	sol(t);
	cout << 0;

	return 0;
}
