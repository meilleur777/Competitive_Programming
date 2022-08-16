#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	vector<int> a(4);
	rep(i, 4) cin >> a[i];
	int x, y, r;
	cin >> x >> y >> r;
	rep(i, 4) {
		if (x==a[i]) {
			cout << i+1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
