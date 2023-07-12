#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int x1=1e6, x2=-1e6, y1=1e6, y2=-1e6;
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		x1=min(x1, a);
		x2=max(x2, a);
		y1=min(y1, b);
		y2=max(y2, b);
	}
	cout << (x2-x1)*(y2-y1);

	return 0;
}
