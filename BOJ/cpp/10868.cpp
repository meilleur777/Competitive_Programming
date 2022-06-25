#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

vector<int> tree;

void update(int node, int left, int right, int index, int x) {
	if (left>index || right<index) return;
	tree[node]=min(tree[node], x);
	if (left!=right) {
		int mid=(left+right)/2;
		update(node*2+1, left, mid, index, x);
		update(node*2+2, mid+1, right, index, x);
	}
}

int query(int node, int left, int right, int begin, int end) {
	if (end<left || right<begin) return INF;
	if (begin<=left && right<=end) return tree[node];
	int mid=(left+right)/2;
	int leftMin=query(node*2+1, left, mid, begin, end);
	int rightMin=query(node*2+2, mid+1, right, begin, end);
	return min(leftMin, rightMin);
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	int treeheight=(int)ceil(log2(N));
	int treesize=(1<<(treeheight+1));
	tree=vector<int>(treesize, INF);
	rep(i, N) {
		int x;
		cin >> x;
		update(0, 0, N-1, i, x);
	}
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		cout << query(0, 0, N-1, a-1, b-1) << '\n';
	}

	return 0;
}
