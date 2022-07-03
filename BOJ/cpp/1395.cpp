#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

vector<int> segtree;
vector<int> lazy;

void lazyupdate(int root, int start, int end) {
	if (!lazy[root]) return;
	if (lazy[root]%2) {
		segtree[root]=(end-start+1)-segtree[root];
		if (start!=end) {
			lazy[root*2+1]++;
			lazy[root*2+2]++;
		}
	}
	lazy[root]=0;
}

void update(int root, int start, int end, int left, int right) {
	lazyupdate(root, start, end);
	if (right<start || end<left) return;
	if (left<=start && end<=right) {
		segtree[root]=(end-start+1)-segtree[root];
		if (start!=end) {
			lazy[root*2+1]++;
			lazy[root*2+2]++;
		}
		return;
	}
	int mid=(start+end)/2;
	update(root*2+1, start, mid, left, right);
	update(root*2+2, mid+1, end, left, right);
	segtree[root]=segtree[root*2+1]+segtree[root*2+2];
}

int getsum(int root, int start, int end, int left, int right) {
	lazyupdate(root, start, end);
	if (right<start || end<left) return 0;
	if (left<=start && end<=right) {
		return segtree[root];
	}
	int mid=(start+end)/2;
	int leftsum=getsum(root*2+1, start, mid, left, right);
	int rightsum=getsum(root*2+2, mid+1, end, left, right);
	return leftsum+rightsum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;

	int height=ceil(log2(n))+1;
	segtree=vector<int>((1<<height), 0);
	lazy=segtree;

	while (m--) {
		int a;
		cin >> a;
		if (a) {
			int b, c;
			cin >> b >> c;
			cout << getsum(0, 0, n-1, b-1, c-1) << '\n';
		}
		else {
			int b, c;
			cin >> b >> c;
			update(0, 0, n-1, b-1, c-1);
		}
	}

	return 0;
}
