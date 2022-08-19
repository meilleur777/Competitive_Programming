#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	int k;
	cin >> s >> k;
	bool flag=true;
	rep(i, (int)s.size()/2) {
		if (s[i]!=s[(int)s.size()-i-1]) flag=false;
	}
	if (flag) cout << "YES";
	else cout << "NO";

	return 0;
}
