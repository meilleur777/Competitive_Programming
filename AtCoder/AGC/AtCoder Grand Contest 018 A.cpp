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

int gcd(int a, int b) {
	if (a%b==0) return b;
	return gcd(b, a%b);
}

int main() {
	init_code();

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	if (k>*max_element(a.begin(), a.end())) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	int g=a[0];
	for (int i=1; i<n; i++) {
		g=gcd(g, a[i]);
	}
	for (int i=0; i<n; i++) {
		if (a[i]>=k && (k-a[i])%g==0) {
			cout << "POSSIBLE";
			return 0;
		}
	}
	cout << "IMPOSSIBLE";

	return 0;
}
