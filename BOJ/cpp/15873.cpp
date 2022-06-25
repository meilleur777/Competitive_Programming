#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	if ((int)s.size()==2) {
		cout << s[0]+s[1]-2*'0';
	}
	else if ((int)s.size()==3) {
		if (s.find('0')==1) {
			cout << 10+s[2]-'0';
		}
		else {
			cout << s[0]-'0'+10;
		}
	}
	else {
		cout << 20;
	}

	return 0;
}
