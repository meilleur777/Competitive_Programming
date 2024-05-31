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
	string s;
	cin >> n >> s;
	vector<int> a(n+1);
	rep(i, n+1) cin >> a[i];
	int k=INF;
	for (int i=0; i<n; i++) {	
		k=min(k, abs(a[i]-a[i+1]));
	}
	cout << k << '\n';
	rep(i, k) {
		for (int j=0; j<=n; j++) {
			cout << (a[j]+i)/k << ' ';
		}
		cout << '\n';
	}

	return 0;
}
