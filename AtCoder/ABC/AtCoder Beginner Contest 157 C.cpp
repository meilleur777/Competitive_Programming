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

	int n, m;
	cin >> n >> m;
	vector<vector<int> > s(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		s[a-1].push_back(b);
	}
	if (n==1) {
		bool ok=true;
		for (auto i:s[0]) {
			if (i!=0) {
				ok=false;
				break;
			}
		}
		if (ok) {
			cout << 0;
			return 0;
		}
	}
	for (int i=(int)pow(10, n-1); i<(int)pow(10, n); i++) {
		string t=to_string(i);
		bool flag=true;
		for (int j=0; j<n; j++) {
			bool ok=true;
			for (auto k:s[j]) {
				if (k+'0'!=t[j]) {
					ok=false;
					break;
				}
			}
			if (!ok) {
				flag=false;
				break;
			}
		}
		if (flag) {
			cout << i;
			return 0;
		}
	}
	cout << -1;

	return 0;
}
