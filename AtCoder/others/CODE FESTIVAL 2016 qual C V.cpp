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

	int k, t;
	cin >> k >> t;
	vector<int> a(t);
	int sum=0;
	rep(i, t) {
		cin >> a[i];
		sum+=a[i];
	}
	int m=*max_element(a.begin(), a.end());
	cout << max(0, 2*m-sum-1);

	return 0;
}
