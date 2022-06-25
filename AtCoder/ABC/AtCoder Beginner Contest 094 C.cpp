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

	int n;
	cin >> n;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	vector<int> t=x;
	sort(t.begin(), t.end());
	int a=t[n/2-1];
	int b=t[n/2];
	rep(i, n) {
		if (x[i]<=a) cout << b << '\n';
		else if (x[i]>=b) cout << a << '\n';
	}

	return 0;
}
