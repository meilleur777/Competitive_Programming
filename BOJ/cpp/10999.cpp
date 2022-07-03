#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

vector<ll> lazy;
vector<ll> segtree;

void updatelazy(int root, int start, int end) {
	if (!lazy[root]) return;

	segtree[root]+=(end-start+1)*lazy[root];
	if (start!=end) {
		lazy[root*2+1]+=lazy[root];
		lazy[root*2+2]+=lazy[root];
	}
	lazy[root]=0LL;
}

void update(int root, int start, int end, int left, int right, ll value) {
	updatelazy(root, start, end);
	if (end<left || right<start) return;
	if (left<=start && end<=right) {
		segtree[root]+=(end-start+1)*value;
		if (start!=end) {
			lazy[root*2+1]+=value;
			lazy[root*2+2]+=value;
		}
		return;
	}
	int mid=(start+end)/2;
	update(root*2+1, start, mid, left, right, value);
	update(root*2+2, mid+1, end, left, right, value);
	segtree[root]=segtree[root*2+1]+segtree[root*2+2];
}

ll getsum(int root, int start, int end, int left, int right) {
	updatelazy(root, start, end);
	if (end<left || right<start) return 0LL;
	if (left<=start && end<=right) return segtree[root];
	int mid=(start+end)/2;
	ll leftsum=getsum(root*2+1, start, mid, left, right);
	ll rightsum=getsum(root*2+2, mid+1, end, left, right);
	return leftsum+rightsum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int height=ceil(log2(n))+1;
	segtree=vector<ll>((1<<height), 0);
	lazy=segtree;

	rep(i, n) {
		ll a;
		cin >> a;
		update(0, 0, n-1, i, i, a);
	}

	k+=m;
	while (k--) {
		int a;
		cin >> a;
		if (a==1) {
			ll b, c, d;
			cin >> b >> c >> d;
			update(0, 0, n-1, b-1, c-1, d);
		}
		else {
			ll b, c;
			cin >> b >> c;
			cout << getsum(0, 0, n-1, b-1, c-1) << '\n';
		}
	}

	return 0;
}
