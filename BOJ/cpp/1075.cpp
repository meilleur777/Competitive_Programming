#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, f;
	cin >> n >> f;
	string s=to_string(n);
	s=s.substr(0, (int)s.size()-2);
	rep(i, 10) rep(j, 10) {
		string t=s+char(i+'0')+char(j+'0');
		int a=stoi(t);
		if (a%f==0) {
			cout << char(i+'0') << char(j+'0');
			return 0;
		}
	}

	return 0;
}
