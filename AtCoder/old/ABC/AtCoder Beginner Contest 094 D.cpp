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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	int m=a[n-1];
	double ans;
	double val=DBL_MAX;
	for (int i=0; i<n-1; i++) {
		if (val>abs(a[i]-m/2.0)) {
			val=abs(a[i]-m/2.0);
			ans=i;
		}
	}
	cout << m << ' ' << a[ans];

	return 0;
}
