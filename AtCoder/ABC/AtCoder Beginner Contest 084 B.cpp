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

	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	if (s[a]!='-') {
		cout << "No";
	}
	else {
		for (int i=0; i<a; i++) {
			if (s[i]<'0' || s[i]>'9') {
				cout << "No";
				return 0;
			}
		}
		for (int i=a+1; i<a+b+1; i++) {
			if (s[i]<'0' || s[i]>'9') {
				cout << "No";
				return 0;
			}
		}
		cout << "Yes";
	}

	return 0;
}
