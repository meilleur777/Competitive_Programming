#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<vector<int>> a(2, vector<int>(3));
	rep(i, 2) rep(j, 3) cin >> a[i][j];
	cout << a[1][0]-a[0][2] << ' ' << a[1][1]/a[0][1] << ' ' << a[1][2]-a[0][0];

	return 0;
}
