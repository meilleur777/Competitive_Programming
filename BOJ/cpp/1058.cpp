#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<bool>> fri(n, vector<bool>(n, false));
	rep(i, n) {
		string s;
		cin >> s;
		rep(j, n) {
			if (s[j]=='Y') {
				fri[i][j]=true;
			}
		}
	}
	int ans=-1;
	for (int i=0; i<n; i++) {
		vector<bool> t(n, false);
		for (int j=0; j<n; j++) {
			if (i==j) continue;
			if (fri[i][j]) t[j]=true;
		}
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				if (j==i || k==i) continue;
				if (fri[i][j] && fri[j][k]) {
					t[k]=true;
				}
			}
		}
		int cnt=0;
		for (int j=0; j<n; j++) {
			cnt+=t[j];
		}
		ans=max(ans, cnt);
	}	
	cout << ans;

	return 0;
}
