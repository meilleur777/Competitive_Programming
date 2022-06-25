#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	init_code();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int tmp=-1;
		string ans;
		rep(i, n) {
			string s;
			int l;
			cin >> s >> l;
			if (l>tmp) {
				ans=s;
				tmp=l;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
