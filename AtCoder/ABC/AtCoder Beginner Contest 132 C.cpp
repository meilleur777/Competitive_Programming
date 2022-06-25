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
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	int cnt=0;
	sort(d.begin(), d.end());
	for (int i=0; i<=1e5; i++) {
		int tmp=lower_bound(d.begin(), d.end(), i)-d.begin();
		if (tmp==n/2) cnt++;
	}
	cout << cnt;

	return 0;
}
