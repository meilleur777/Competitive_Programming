#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m, 0));
	rep(i, 2) rep(j, n) rep(k, m) {
		int b;
		cin >> b;
		a[j][k]+=b;
	}
	rep(i, n) {
		rep(j, m) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
