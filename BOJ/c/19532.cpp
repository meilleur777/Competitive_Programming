#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	for (int x=-999; x<=999; x++) {
		for (int y=-999; y<=999; y++) {
			if (a*x+b*y==c && d*x+e*y==f) {
				cout << x << ' ' << y;
				return 0;
			}
		}
	}

	return 0;
}
