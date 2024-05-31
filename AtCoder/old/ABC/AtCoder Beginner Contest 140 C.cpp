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
	vector<int> b(n-1);
	rep(i, n-1) cin >> b[i];
	vector<int> a(n);
	a[0]=b[0];
	a[1]=b[0];
	for (int i=1; i<n-1; i++) {
		a[i]=min(a[i], b[i]);
		a[i+1]=b[i];
	}
	int sum=0;
	rep(i, n) {
		sum+=a[i];
	}
	cout << sum;

	return 0;
}
