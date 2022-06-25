#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	cout << ((s[0]&255)-234)*4096+((s[1]&255)-176)*64+(s[2]&255)-127;

	return 0;
}
