#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

vector<int> segtree;
vector<int> lazy;

void lazyupdate(int root, int start, int end) {
	if (!lazy[root]) return;
	if ((end-start+1)%2) {
		segtree[root]=(segtree[root])^lazy[root];
	}
	if (start!=end) {
		lazy[root*2+1]^=lazy[root];
		lazy[root*2+2]^=lazy[root];
	}
	lazy[root]=0;
}

void update(int root, int start, int end, int left, int right, int value) {
	lazyupdate(root, start, end);
	if (end<left || right<start) return;
	if (left<=start && end<=right) {
		if ((end-start+1)%2) {
			segtree[root]^=value;
		}
		if (start!=end) {
			lazy[root*2+1]^=value;
			lazy[root*2+2]^=value;
		}
		return;
	}
	int mid=(start+end)/2;
	update(root*2+1, start, mid, left, right, value);
	update(root*2+2, mid+1, end, left, right, value);
	segtree[root]=segtree[root*2+1]^segtree[root*2+2];
}

int query(int root, int start, int end, int left, int right) {
	lazyupdate(root, start, end);
	if (end<left || right<start) return 0;
	if (left<=start && end<=right) {
		return segtree[root];
	}
	int mid=(start+end)/2;
	int leftquery=query(root*2+1, start, mid, left, right);
	int rightquery=query(root*2+2, mid+1, end, left, right);
	return leftquery^rightquery;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	int height=ceil(log2(n))+1;
	segtree=vector<int>(1<<height, 0);
	lazy=segtree;

	rep(i, n) {
		int a;
		cin >> a;
		update(0, 0, n-1, i, i, a);
	}

	int m;
	cin >> m;
	while (m--) {
		int a;
		cin >> a;
		if (a==1) {
			int i, j, k;
			cin >> i >> j >> k;
			update(0, 0, n-1, i, j, k);
		}	
		else {
			int i, j;
			cin >> i >> j;
			cout << query(0, 0, n-1, i, j) << '\n';
		}
	}

	return 0;
}
