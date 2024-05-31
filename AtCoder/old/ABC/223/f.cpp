#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

vector<intp> tree;

void upd(int node, int left, int right, int ind, intp x) {
	if (ind<left || right<ind) return;
	if (left==right) {
		tree[node]=x;
		return;
	}
	int mid=(left+right)/2;
	upd(node*2+1, left, mid, ind, x);
	upd(node*2+2, mid+1, right, ind, x);
	tree[node].first=tree[node*2+1].first+tree[node*2+2].first;
	tree[node].second=min(tree[node*2+1].second, tree[node*2+1].first+tree[node*2+2].second);
}

intp query(int node, int left, int right, int begin, int end) {
	if (end<left || right<begin) return {0, INF};
	if (begin<=left && right<=end) return tree[node];
	int mid=(left+right)/2;
	intp leq=query(node*2+1, left, mid, begin, end);
	intp riq=query(node*2+2, mid+1, right, begin, end);
	return {leq.first+riq.first, min(leq.second, leq.first+riq.second)};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, q;
	string s;
	cin >> n >> q >> s;
	int th=(int)ceil(log2(n+1));
	th=(1<<(th+1));
	tree=vector<intp>(th, {0, INF});
	vector<intp> v(n);
	rep(i, n) {
		if (s[i]=='(') v[i]={1, 1};
		else v[i]={-1, -1};
	}
	rep(i, n) {
		upd(0, 0, n-1, i, v[i]);
	}
	rep(i, q) {
		int a, b, c;
		cin >> a >> b >> c;
		b--, c--;
		if (a==1) {
			swap(v[b], v[c]);
			upd(0, 0, n-1, b, v[b]);
			upd(0, 0, n-1, c, v[c]);
		}
		else {
			if (query(0, 0, n-1, b, c)==make_pair(0, 0)) {
				cout << "Yes\n";
			}
			else cout << "No\n";
		}
	}

	return 0;
}
