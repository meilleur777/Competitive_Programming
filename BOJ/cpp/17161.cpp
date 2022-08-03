#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s, e;
	cin >> s >> e;

	function<void(int, int, int, int)> sol=[&](int sy, int sx, int ey, int ex) {
		if (sy>ey || sx>ex) return;
		if (sy==ey) {
			for (int i=sx; i<ex; i++) {
				cout << "a " << e[i] << '\n';
			}
			return;
		}

		int midy=(sy+ey)/2;
		int width=ex-sx+1;

		int upper[2][width]={0};
		for (int i=sx; i<=ex; i++) {
			upper[1][i-sx]=i-sx;
		}
		for (int i=sy+1; i<=midy; i++) {
			for (int j=sx; j<=ex; j++) {
				upper[0][j-sx]=upper[1][j-sx];
			}
			upper[1][0]=i-sy;
			for (int j=sx+1; j<=ex; j++) {
				if (s[i-1]==e[j-1]) {
					upper[1][j-sx]=upper[0][j-sx-1];
				}
				else {
					upper[1][j-sx]=min({upper[1][j-sx-1], upper[0][j-sx], upper[0][j-sx-1]})+1;
				}
			}
		}

		int lower[2][width]={0};
		for (int i=ex; i>=sx; i--) {
			lower[0][i-sx]=ex-i;
		}
		for (int i=ey-1; i>=midy+1; i--) {
			for (int j=ex; j>=sx; j--) {
				lower[1][j-sx]=lower[0][j-sx];
			}
			lower[0][ex-sx]=ey-i;
			for (int j=ex-1; j>=sx; j--) {
				if (s[i]==e[j]) {
					lower[0][j-sx]=lower[1][j-sx+1];
				}
				else {
					lower[0][j-sx]=min({lower[0][j-sx+1], lower[1][j-sx], lower[1][j-sx+1]})+1;	
				}
			}
		}

		int index=-1;
		int mn=1e8;
		int dir=-1;
		int nxt=0;
		for (int i=sx; i<=ex; i++) {
			int tmp=upper[1][i-sx]+lower[0][i-sx]+1;
			if (tmp<mn) {
				index=i;
				mn=tmp;
				dir=1;
			}
		}
		for (int i=sx; i<ex; i++) {
			int ttt=e[i]==s[midy];
			int tmp=upper[1][i-sx]+lower[0][i-sx+1]+1-ttt;
			if (tmp<mn) {
				nxt=1;
				index=i;
				mn=tmp;
				dir=2+ttt;
			}
		}

		sol(sy, sx, midy, index);
		switch (dir) {
			case 1: cout << "d " << s[midy] << '\n'; break;
			case 2: cout << "m " << e[index] << '\n'; break;
			case 3: cout << "c " << e[index] << '\n'; break;
		}
		sol(midy+1, index+nxt, ey, ex);
	};
	sol(0, 0, (int)s.size(), (int)e.size());

	return 0;
}
