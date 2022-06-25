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
	vector<int> l(n);
	rep(i, n) cin >> l[i];
	sort(l.begin(), l.end());
	ll ans=0;
	for (int a=0; a<n-2; a++) {
		for (int b=a+1; b<n-1; b++) {
			int lo=upper_bound(l.begin()+b+1, l.end(), l[b]-l[a])-l.begin();
			int hi=lower_bound(l.begin()+b+1, l.end(), l[b]+l[a])-l.begin()-1;
			ans+=max(0, hi-lo+1);
		}
	}
	cout << ans;

	return 0;
}
