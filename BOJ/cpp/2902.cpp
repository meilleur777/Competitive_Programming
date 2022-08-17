#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	cin >> s;
	string ans;
	ans+=s[0];
	for (int i=1; i<(int)s.size(); i++) {
		if (s[i-1]=='-') {
			ans+=s[i];
		}
	}
	cout << ans;	

	return 0;
}
