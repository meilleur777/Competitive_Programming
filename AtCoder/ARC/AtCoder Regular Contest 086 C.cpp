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

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> cnt(n+1, 0);
	rep(i, n) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(cnt.begin(), cnt.end());
	int sta=lower_bound(cnt.begin(), cnt.end(), 1)-cnt.begin();
	int ans=0;
	int tmp=cnt.end()-lower_bound(cnt.begin(), cnt.end(), 1);
	if (tmp<=k) {
		cout << 0;
		return 0;
	}
	for (int i=sta; i<cnt.size(); i++) {
		ans+=cnt[i];
		tmp--;
		if (tmp<=k) break;
	}
	cout << ans;

	return 0;
}
