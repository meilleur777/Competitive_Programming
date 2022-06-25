#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int l, n;
	cin >> l >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	string ans=string(l*l, 'Z'+1);
	function<void(int, vector<int>)> sol=[&](int now, vector<int> sel) {
		if (now==l) {
			string t;
			for (auto i:sel) {
				t+=s[i];
			}
			for (int i=0; i<l; i++) {
				for (int j=0; j<i; j++) {
					if (t[i*l+j]!=t[j*l+i]) {
						return;
					}
				}
			}
			ans=min(ans, t);
			return;
		}
		for (int i=0; i<n; i++) {
			bool flag=true;
			for (auto j:sel) {
				if (i==j) {
					flag=false;
					break;
				}
			}
			if (flag) {
				vector<int> qqq=sel;
				qqq.push_back(i);
				sol(now+1, qqq);
			}
		}
	};
	vector<int> kkk;
	sol(0, kkk);
	if (ans[0]=='Z'+1) cout << "NONE";
	else {
		rep(i, l) {
			cout << ans.substr(i*l, l) << '\n';
		}
	}

	return 0;
}
