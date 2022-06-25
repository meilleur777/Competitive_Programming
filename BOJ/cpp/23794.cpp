#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	string t(n+2, '@');
	string k(n, ' ');
	k="@"+k+"@";
	cout << t << '\n';
	rep(i, n) cout << k << '\n';
	cout << t;

	return 0;
}
