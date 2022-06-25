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
	cout.precision(1);

	int n;
	cin >> n;
	ll sum=0;
	vector<ll> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	x.push_back(x[0]), y.push_back(y[0]);
	rep(i, n) sum+=x[i]*y[i+1]-x[i+1]*y[i];
	cout << fabs(sum/2.0);

	return 0;
}
