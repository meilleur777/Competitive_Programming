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

	vector<int> a(4);
	rep(i, 4) cin >> a[i];
	int sum=0;
	rep(i, 4) sum+=a[i];
	for (int i=0; i<(1<<4); i++) {
		int tmp=0;
		for (int j=0; j<4; j++) {
			if (i&(1<<j)) tmp+=a[j];
		}
		if (tmp*2==sum) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";

	return 0;
}
