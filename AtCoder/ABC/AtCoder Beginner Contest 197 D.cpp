#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();
	cout << fixed;
	cout.precision(10);

	int n;
	cin >> n;
	ld x0, y0, x2, y2;
	cin >> x0 >> y0 >> x2 >> y2;	
	ld r=sqrtl((x0-x2)*(x0-x2)+(y0-y2)*(y0-y2))/2.0;
	ld ox=(x0+x2)/2.0, oy=(y0+y2)/2.0;
	ld theta=atan2(y0-oy, x0-ox)+atan(1)*8.0/n;
	ld x1=r*cos(theta)+ox;
	ld y1=r*sin(theta)+oy;
	cout << x1 << ' ' << y1 << '\n';

	return 0;
}
