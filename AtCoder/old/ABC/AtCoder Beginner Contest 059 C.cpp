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

vector<ll> tree;

void upd(int ind, ll x) {
	for (; ind<tree.size(); ind+=(ind&-ind)) {
		tree[ind]+=x;
	}
}

ll fensum(int ind) {
	ll ret=0;
	for (; ind>0; ind&=ind-1) {
		ret+=tree[ind];
	}
	return ret;
}

int main() {
	init_code();

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	tree=vector<ll>(n+1, 0);
	rep(i, n) upd(i+1, a[i]);
	ll can1=0, can2=0;
	/*+ - + -...*/
	for (int i=1; i<=n; i++) {
		ll tmp=fensum(i);
		if (i%2) {
			if (tmp<=0) {
				upd(i, 1-tmp);
				can1+=1-tmp;
			}
		}
		else {
			if (tmp>=0) {
				upd(i, -tmp-1);
				can1+=tmp+1;
			}
		}
	}
	tree=vector<ll>(n+1, 0);
	rep(i, n) upd(i+1, a[i]);
	for (int i=1; i<=n; i++) {
		ll tmp=fensum(i);
		if (i%2==0) {
			if (tmp<=0) {
				upd(i, 1-tmp);
				can2+=1-tmp;
			}
		}
		else {
			if (tmp>=0) {
				upd(i, -tmp-1);
				can2+=tmp+1;
			}
		}
	}
	cout << min(can1, can2);

	return 0;
}
