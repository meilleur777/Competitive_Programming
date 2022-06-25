#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> s(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> s[i][j];
	int ans=1e7;
	for (int i=1; i<(1<<(n-1)); i++) {
		vector<vector<int>> a(2);
		for (int j=0; j<n; j++) {
			a[!!(i&(1<<j))].push_back(j);
		}
		int tmp=0;
		for (int k=0; k<2; k++) {
			for (int j=0; j<(int)a[k].size(); j++) {
				for (int l=0; l<(int)a[k].size(); l++) {
					int t=s[a[k][j]][a[k][l]];
					tmp+=(!k)?t:-t;
				}
			}
		}
		ans=min(ans, abs(tmp));
	}
	cout << ans;

	return 0;
}
