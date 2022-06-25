#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	function<bool(int, int)> sol=[&](int sta, int ed) {
		if (sta==ed) return true;
		int len=ed-sta+1;
		len/=2;
		return s.substr(sta, len)==s.substr(ed-len+1, len) && sol(sta, sta+len-1) && sol(ed-len+1, ed);
	};
	if (sol(0, (int)s.size()-1)) cout << "AKARAKA";
	else cout << "IPSELENTI";

	return 0;
}
