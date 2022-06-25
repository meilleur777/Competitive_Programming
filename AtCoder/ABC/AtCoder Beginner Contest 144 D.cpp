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
const ld pi = (acos(-1));

int main() {
	init_code();
	cout << fixed;
	cout.precision(10);

	ld a, b, x;
	cin >> a >> b >> x;
	if (a*a*b/2.0<x) {
		cout << atan(2*b/a-2*x/(a*a*a))*180.0/pi;
	}
	else {
		cout << atan((a*b*b)/(2*x))*180.0/pi;
	}

	return 0;
}
