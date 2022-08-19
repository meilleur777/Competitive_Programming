#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int c;
	cin >> c;
	while (c--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		rep(i, n) cin >> a[i];

		vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>((1<<(m+1)), -1)));
		function<int(int, int, int)> sol=[&](int y, int x, int state) {
			if (x>=m) {
				if (y==0) return 0;
				return sol(y-1, 0, state);
			}
			int& ret=dp[y][x][state];
			if (ret!=-1) return ret;
			ret=0;

			if (a[y][x]!='x')  {
				if (x==0) {
					if (y==n-1) {
						ret=max(ret, sol(y, x+1, (((state<<1)|1)&((1<<(m+1))-1)))+1);
					}
					else {
						if (((1<<(m-2))&state)==0) {
							ret=max(ret, sol(y, x+1, (((state<<1)|1)&((1<<(m+1))-1)))+1);
						}
					}
				}
				else if (x==m-1) {
					if (y==n-1) {
						if ((1&state)==0) {
							ret=max(ret, sol(y, x+1, (((state<<1)|1)&((1<<(m+1))-1)))+1);
						}	
					}
					else {
						if ((1&state)==0 && ((1<<m)&state)==0) {
							ret=max(ret, sol(y, x+1, (((state<<1)|1)&((1<<(m+1))-1)))+1);
						}
					}
				}
				else {
					if (y==n-1) {
						if ((1&state)==0) {
							ret=max(ret, sol(y, x+1, (((state<<1)|1)&((1<<(m+1))-1)))+1);
						}	
					}
					else {
						if ((1&state)==0 && ((1<<(m-2))&state)==0 && ((1<<m)&state)==0) {
							ret=max(ret, sol(y, x+1, (((state<<1)|1)&((1<<(m+1))-1)))+1);
						}
					}
				}
			}

			ret=max(ret, sol(y, x+1, ((state<<1)&((1<<(m+1))-1))));
			return ret;
		};

		cout << sol(n-1, 0, 0) << '\n';
	}

	return 0;
}
