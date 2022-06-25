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
	vector<int> p(n), q(n);
	rep(i, n) cin >> p[i];
	rep(i, n) cin >> q[i];
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		a[i]=i+1;
	}
	int resp, resq;
	int cnt=1;
	do {
		if (p==a) {
			resp=cnt;
		}
		if (q==a) {
			resq=cnt;
		}
		cnt++;
	} while (next_permutation(a.begin(), a.end()));
	cout << abs(resp-resq);

	return 0;
}
