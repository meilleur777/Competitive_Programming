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
	rep(i, n) {
		cin >> a[i];
	}
	int bd=*max_element(a.begin(), a.end());
	int mx=-1, ans;
	for (int i=2; i<=bd; i++) {
		int cnt=0;
		rep(j, n) {
			cnt+=(a[j]%i==0);
		}
		if (cnt>mx) {
			mx=cnt;
			ans=i;
		}
	}
	cout << ans;

	return 0;
}
