#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	rep(i, 3) {
		if (s[i]==s[i+1]) {
			cout << "Bad";
			return 0;
		}
	}
	cout << "Good";

	return 0;
}
