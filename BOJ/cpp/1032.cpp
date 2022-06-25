#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	for (int i=0; i<(int)s[0].size(); i++) {
		bool flag=true;
		for (int j=0; j<n-1; j++) {
			if (s[j][i]!=s[j+1][i]) {
				flag=false;
				break;
			}
		}
		if (flag) cout << s[0][i];
		else cout << '?';
	}

	return 0;
}
