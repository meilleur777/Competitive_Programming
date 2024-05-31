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

vector<int> tree;

void upd(int node, int left, int right, int ind, int x) {
	if (ind<left || right<ind) return;
	if (left==right) {
		tree[node]=max(tree[node], x);
		return;
	}
	int mid=(left+right)/2;
	upd(node*2, left, mid, ind, x);
	upd(node*2+1, mid+1, right, ind, x);
	tree[node]=max(tree[node*2], tree[node*2+1]);
}

int query(int node, int left, int right, int begin, int end) {
	if (end<left || right<begin) return 0;
	if (begin<=left && right<=end) return tree[node];
	int mid=(left+right)/2;
	int leq=query(node*2, left, mid, begin, end);
	int riq=query(node*2+1, mid+1, right, begin, end);
	return max(leq, riq);
}

int main() {
	init_code();

	int n, k;
	cin >> n >> k;
	int th=(int)ceil(log2(3e5));
	th=(1<<(th+1));
	tree=vector<int>(th, 0);
	int ans=-1;
	rep(i, n) {
		int x;
		cin >> x;
		int now=query(1, 0, 3e5, max(0, x-k), min((int)3e5, x+k))+1;
		upd(1, 0, 3e5, x, now);
		ans=max(ans, now);
	}
	cout << ans;

	return 0;
}
