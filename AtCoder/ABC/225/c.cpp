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

	int n, m;
	cin >> n >> m;
	vector<vector<int>> b(n, vector<int>(m)), c;
	c=b;
	rep(i, n) rep(j, m) {
		cin >> b[i][j];
		b[i][j]--;
	}
	if (b[0][0]%7+m-1>=7) {
		cout << "No";
		return 0;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			c[i][j]=b[0][0]+j+i*7;	
		}
	}
	if (c==b) cout << "Yes";
	else cout << "No";

	return 0;
}
