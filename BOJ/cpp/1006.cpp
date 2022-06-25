#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, w;
		cin >> n >> w;
		vector<vector<int>> a(2, vector<int>(n));
		rep(i, 2) rep(j, n) cin >> a[i][j];

		int inf=1e7;
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(4, inf)));

		if (n==1) {
			if (a[0][0]+a[1][0]<=w) cout << 1 << '\n';
			else cout << 2 << '\n';
		}
		else {
			function<int(int, int, int)> sol=[&](int now, int sta, int last) {
				if (now==n) {
					if (sta==last) return 0;
					return inf;
				}
				int &ret=dp[now][sta][last];
				if (ret!=inf) return ret;

				if (sta==0) {
					if (a[0][now]+a[1][now]<=w) ret=min(ret, sol(now+1, 0, last)+1);
					else ret=min(ret, sol(now+1, 0, last)+2);

					if (a[0][now]+a[0][(now+1)%n]<=w ||
						a[0][now]+a[1][now]<=w) ret=min(ret, sol(now+1, 1, last)+2);
					else ret=min(ret, sol(now+1, 1, last)+3);

					if (a[1][now]+a[1][(now+1)%n]<=w || 
						a[0][now]+a[1][now]<=w) ret=min(ret, sol(now+1, 2, last)+2);
					else ret=min(ret, sol(now+1, 2, last)+3);

					if ((a[1][now]+a[1][(now+1)%n]<=w && a[0][now]+a[0][(now+1)%n]<=w) ||
						(a[0][now]+a[1][now]<=w && a[0][(now+1)%n]+a[1][(now+1)%n]<=w)) ret=min(ret, sol(now+1, 3, last)+2);
					else if ((a[1][now]+a[1][(now+1)%n]<=w || a[0][now]+a[0][(now+1)%n]<=w) ||
						(a[0][now]+a[1][now]<=w || a[0][(now+1)%n]+a[1][(now+1)%n]<=w)) ret=min(ret, sol(now+1, 3, last)+3);
					else ret=min(ret, sol(now+1, 3, last)+4);
				}
				else if (sta==1) {
					ret=min(ret, sol(now+1, 0, last)+1);

					ret=min(ret, sol(now+1, 1, last)+2);

					if (a[1][now]+a[1][(now+1)%n]<=w) ret=min(ret, sol(now+1, 2, last)+1);
					else ret=min(ret, sol(now+1, 2, last)+2);

					if ((a[0][(now+1)%n]+a[1][(now+1)%n]<=w) ||
						(a[1][now]+a[1][(now+1)%n]<=w)) ret=min(ret, sol(now+1, 3, last)+2);
					else ret=min(ret, sol(now+1, 3, last)+3);
				}	
				else if (sta==2) {
					ret=min(ret, sol(now+1, 0, last)+1);

					if (a[0][now]+a[0][(now+1)%n]<=w) ret=min(ret, sol(now+1, 1, last)+1);
					else ret=min(ret, sol(now+1, 1, last)+2);

					ret=min(ret, sol(now+1, 2, last)+2);

					if ((a[0][now]+a[0][(now+1)%n]<=w) ||
						(a[0][(now+1)%n]+a[1][(now+1)%n]<=w)) ret=min(ret, sol(now+1, 3, last)+2);
					else ret=min(ret, sol(now+1, 3, last)+3);
				}	
				else if (sta==3) {
					ret=min(ret, sol(now+1, 0, last));

					ret=min(ret, sol(now+1, 1, last)+1);

					ret=min(ret, sol(now+1, 2, last)+1);

					if (a[0][(now+1)%n]+a[1][(now+1)%n]<=w) ret=min(ret, sol(now+1, 3, last)+1);
					else ret=min(ret, sol(now+1, 3, last)+2);
				}
				return ret;
			};

			int ans=inf;
			rep(i, 4) ans=min(ans, sol(0, i, i));
			cout << ans << '\n';
		}
	}

	return 0;
}
