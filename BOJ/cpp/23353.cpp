#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	vector<vector<int>> col, row, di1, di2;
	a=row=di1=di2=col;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (j==0) col[i][j]=a[i][j]==1;
			else col[i][j]=col[i][j-1]+(a[i][j]==1);
		}
	}

	return 0;
}
