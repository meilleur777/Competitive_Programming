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

void upd(int node, int left, int right, int ind, ll x) {
	if (ind<left || right<ind) return;
	if (left==right) {
		tree[node]^=x;
		return;
	}
	int mid=(left+right)/2;
	upd(node*2, left, mid, ind, x);
	upd(node*2+1, mid+1, right, ind, x);
	tree[node]=tree[node*2]^tree[node*2+1];
}

ll query(int node, int left, int right, int begin, int end) {
	if (end<left || right<begin) return 0;
	if (begin<=left && right<=end) return tree[node];
	int mid=(left+right)/2;
	ll leq=query(node*2, left, mid, begin, end);
	ll riq=query(node*2+1, mid+1, right, begin, end);
	return leq^riq;
}

int main() {
	init_code();

	int n, q;
	cin >> n >> q;
	int th=(int)ceil(log2(n));
	th=(1<<(th+1));
	tree=vector<ll>(th, 0);
	rep(i, n) {
		ll a;
		cin >> a;
		upd(1, 1, n, i+1, a);
	}
	while (q--) {
		ll t, x, y;
		cin >> t >> x >> y;
		if (t==1) {
			upd(1, 1, n, x, y);
		}
		else {
			cout << query(1, 1, n, x, y) << '\n';
		}
	}

	return 0;
}
