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
	vector<ll> le, ri;
	rep(i, n) {
		int x;
		cin >> x;
		if (x<0) {
			x=-x;
			le.push_back(x);
		}
		else if (x>0) ri.push_back(x);
		else k--;
	}
	if (k==0) {
		cout << 0;
		return 0;
	}
	reverse(le.begin(), le.end());
	ll res=LLONG_MAX;
	for (int i=0; i<le.size(); i++) {
		int tmp=k-(i+1)-1;
		if (tmp==-1) break;
		if (tmp<ri.size()) {
			res=min(res, 2*le[i]+ri[tmp]);
		}
	}
	for (int i=0; i<ri.size(); i++) {
		int tmp=k-(i+1)-1;
		if (tmp==-1) break;
		if (tmp<le.size()) {
			res=min(res, 2*ri[i]+le[tmp]);
		}
	}
	if (le.size()>=k) {
		res=min(res, le[k-1]);
	}
	if (ri.size()>=k) {
		res=min(res, ri[k-1]);
	}
	cout << res;

	return 0;
}
