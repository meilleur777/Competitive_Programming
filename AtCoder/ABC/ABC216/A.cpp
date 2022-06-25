#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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
	cin >> s;
	if (s[1]=='.') {
		if (s[2]>='0' && s[2]<='2') {
			cout << s[0] << '-';
		}
		else if (s[2]>='3' && s[2]<='6') {
			cout << s[0];
		}
		else {
			cout << s[0] << '+';
		}
	}
	else {
		if (s[3]>='0' && s[3]<='2') {
			cout << s[0] << s[1] << '-';
		}
		else if (s[3]>='3' && s[3]<='6') {
			cout << s[0] << s[1];
		}
		else {
			cout << s[0] << s[1] << '+';
		}
	}

	return 0;
}
