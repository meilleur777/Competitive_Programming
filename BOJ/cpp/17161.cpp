#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s, e;
	cin >> s >> e;
	function<void(int, int> Hirschberg=[&](int sy, int sx, int ey, int ex) {
		if (sy==ey && sx==ex) return;
		if (sy==ey) {
			Hirschberg(sy, sx, ey, ex-1);
			cout << 'a' << ' ' << e[ex] << '\n';
			return;
		}
		if (sx==ex) {
			Hirschberg(sy, sx, ey-1, ex);
			cout << 'd' << ' ' << s[ey] << '\n';
			return;
		}

		int midy=(sy+ey)/2;

		//upper
		vector<vector<int>> forupper(2, vector<int>((int)e.size()+1));
		for (int i=0; i<(int)e.size(); i++) {
			
		}

		//lower

		//find minimum

		//recursion

	};
	Hirschberg((int)s.size()-1, (int)e.size()-1);

	return 0;
}
