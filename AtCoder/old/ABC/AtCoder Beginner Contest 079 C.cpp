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

	string s;
	cin >> s;
	vector<int> v(4);
	rep(i, 4) {
		v[i]=s[i]-'0';
	}
	for (int i=0; i<(1<<3); i++) {
		int tmp=v[0];
		for (int j=0; j<3; j++) {
			if (i&(1<<j)) tmp-=v[j+1];
			else tmp+=v[j+1];
		}
		if (tmp==7) {
			cout << v[0];
			for (int j=0; j<3; j++) {
				if (i&(1<<j)) cout << '-';
				else cout << '+';
				cout << v[j+1];
			}
			cout << "=7";
			return 0;
		}
	}

	return 0;
}
