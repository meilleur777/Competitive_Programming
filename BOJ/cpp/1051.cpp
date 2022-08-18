#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
		
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	rep(i, n) cin >> a[i];

	int ans=-1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			for (int k=0; k<n; k++) {
				for (int l=0; l<m; l++) {
					if (abs(i-k)!=abs(j-l)) continue;

					if (a[i][j]==a[i][l] && a[i][j]==a[k][j] && a[i][j]==a[k][l]) {
						ans=max(ans, abs(i-k+1));
					}
				}
			}
		}
	}
	cout << ans*ans;

	return 0;
}
