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
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (n%2) {
		int lo=a[n/2];
		int hi=b[n/2];
		cout << hi-lo+1;
	}
	else {
		int lo=a[n/2]+a[n/2-1];
		int hi=b[n/2]+b[n/2-1];
		cout << hi-lo+1;
	}

	return 0;
}
