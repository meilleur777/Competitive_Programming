#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

	int N;
	cin >> N;
	vector<ll> v(N), z(N);
	rep(i, N) {
		ll x, y;
		cin >> x >> y;
		v[i]=x+y;
		z[i]=x-y;
	}
	cout << max(*max_element(v.begin(), v.end())-*min_element(v.begin(), v.end()), 
	*max_element(z.begin(), z.end())-*min_element(z.begin(), z.end()));

	return 0;
}
