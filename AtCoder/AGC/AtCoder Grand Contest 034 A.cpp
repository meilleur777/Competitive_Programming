#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
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

	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	a--, b--, c--, d--;
	string s;
	cin >> s;
	for (int i=a; i<=max(c, d)-1; i++) {
		if (s[i]=='#' && s[i+1]=='#') {
			cout << "No";
			return 0;
		}
	}
	if (c>d) {
		bool flag=false;
		for (int i=b; i<=d; i++) {
			if (s[i-1]=='.' && s[i]=='.' && s[i+1]=='.') {
				flag=true;
				break;
			}
		}
		if (!flag) {
			cout << "No";
			return false;
		}
	}
	cout << "Yes";

	return 0;
}
