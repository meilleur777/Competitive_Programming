#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	char s[(int)1e6+1], p[(int)1e6+1];
	cin >> s >> p;
	cout << (!!strstr(s, p));

	return 0;
}
