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
	cout << fixed;
	cout.precision(20);

	int n, k;
	cin >> n >> k;
	ld ans=0.0;
	for (int i=1; i<=n; i++) {
		int cnt=0;
		while (true) {
			if (i*(int)pow(2, cnt)>=k) {
				break;
			}
			else cnt++;
		}
		ans+=1/pow(2, cnt);
	}
	cout << ans/n;

	return 0;
}
