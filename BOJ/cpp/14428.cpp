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

vector<int> A;
vector<intp> tree;

intp matr(int node, int left, int right) {
	if (left==right) return tree[node]={A[left], left};
	int mid=(left+right)/2;
	intp le=matr(node*2, left, mid);
	intp ri=matr(node*2+1, mid+1, right);
	return tree[node]=min(le, ri);
}

intp update(int node, int left, int right, int index, int x) {
	if (index<left || right<index) return tree[node];
	if (left==right) return tree[node]={x, index};
	int mid=(left+right)/2;
	intp leftup=update(node*2, left, mid, index, x);
	intp rightup=update(node*2+1, mid+1, right, index, x);
	return tree[node]=min(leftup, rightup);
}

intp query(int node, int left, int right, int begin, int end) {
	if (end<left || right<begin) return {INF, INF};
	if (begin<=left && right<=end) return tree[node];
	int mid=(left+right)/2;
	intp leftqu=query(node*2, left, mid, begin, end);
	intp rightqu=query(node*2+1, mid+1, right, begin, end);
	return min(leftqu, rightqu);
}

int main() {
	init_code();

	int n;
	cin >> n;
	int th=(int)ceil(log2(n));
	int ts=(1<<(th+1));
	tree.resize(ts+1);
	A.resize(n);
	rep(i, n) cin >> A[i];
	matr(1, 0, n-1);
	int m;
	cin >> m;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a==1) {
			update(1, 0, n-1, b-1, c);
		}	
		else {
			cout << query(1, 0, n-1, b-1, c-1).second+1 << '\n';
		}
	}

	return 0;
}
