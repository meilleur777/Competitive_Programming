#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int a, b, c, n;
	cin >> a >> b >> c >> n;
	int mx=-1;
	rep(i, n) {
		int x, y, z;
		int tmp=0;
		rep(j, 3) {
			cin >> x >> y >> z;
			tmp+=x*a+y*b+z*c;
		}
		mx=max(mx, tmp);
	}
	cout << mx;

	return 0;
}
