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

	string s, t;
	cin >> s >> t;
	int n=s.size();
	bool flag=false;
	for (int i=0; i<n-1; i++) {
		if (s[i]!=t[i]) {
			if (flag) {
				cout << "No";
				return 0;
			}
			swap(s[i], s[i+1]);
			if (s.substr(i, 2)!=t.substr(i, 2)) {
				cout << "No";
				return 0;
			}
			else {
				flag=true;
			}
		}
	}
	cout << "Yes";

	return 0;
}
