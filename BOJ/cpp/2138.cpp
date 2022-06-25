#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	rep(i, n) {
		if (s[i]==t[i]) s[i]='0';
		else s[i]='1';
	}
	auto sol=[&](string str, int cnt) {
		for (int i=0; i<n-1; i++) {
			if (str[i]=='1') {
				for (int j=i; j<i+3 && j<n; j++) {
					if (str[j]=='0') str[j]='1';
					else str[j]='0';
				}
				cnt++;
			}
		}
		if (str[n-1]=='0') return cnt;
		else return (int)1e9;
	};
	string qqq=s;
	if (qqq[0]=='0') qqq[0]='1';
	else qqq[0]='0';
	if (qqq[1]=='0') qqq[1]='1';
	else qqq[1]='0';
	int ans=min(sol(qqq, 1), sol(s, 0));
	if (ans==1e9) cout << -1;
	else cout << ans;

	return 0;
}
