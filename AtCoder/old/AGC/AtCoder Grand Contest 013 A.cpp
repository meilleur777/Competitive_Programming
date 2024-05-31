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
	int turn=0;
	int cnt=1;
	for (int i=0; i<n-1; i++) {
		if (turn==0) {
			if (a[i]>a[i+1]) {
				turn=-1;
			}
			else if (a[i]==a[i+1]) {
				continue;
			}
			else {
				turn=1;
			}
		}
		else if (turn==1) {
			if (a[i]>a[i+1]) {
				cnt++;
				turn=0;
			}
		}
		else if (turn==-1) {
			if (a[i]<a[i+1]) {
				cnt++;
				turn=0;
			}
		}
	}
	cout << cnt;

	return 0;
}
