#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n%2) {
			cout << "NO\n";
			continue;
		}
		vector<vector<int>> a(n, vector<int>(5));
		rep(i, n) rep(j, 5) cin >> a[i][j];
		bool flag=false;
		for (int i=0; i<5; i++) {
			for (int j=0; j<5; j++) {
				if (i==j) continue;
				int cnt=0, icnt=0, jcnt=0;
				for (int k=0; k<n; k++) {
					if (a[k][i] && a[k][j]) cnt++;
					else if (a[k][i]) icnt++;
					else if (a[k][j]) jcnt++;
				}
				if (icnt>n/2 || jcnt>n/2) continue;
				if (cnt+icnt+jcnt==n) {
					flag=true;
					break;
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
