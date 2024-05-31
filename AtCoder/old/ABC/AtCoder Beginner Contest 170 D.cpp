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
	vector<int> cnt(1e6+1, 0);
	rep(i, n) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	if (cnt[1]>1) {
		cout << 0;
		return 0;
	}
	if (cnt[1]==1) {
		cout << 1;
		return 0;
	}
	int ans=0;
	for (int i=0; i<n; i++) {
		bool flag=false;
		if (cnt[a[i]]>1) continue;
		for (int j=2; j*j<=a[i]; j++) {
			if (a[i]%j==0) {
				if (cnt[j] || cnt[a[i]/j]) {
					flag=true;
					break;
				}
			}
		}
		if (!flag) {
			ans++;
		}
	}
	cout << ans;

	return 0;
}
