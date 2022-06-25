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
		tree[node]+=x;
		return;
	}
	int mid=(left+right)/2;
	upd(node*2, left, mid, ind, x);
	upd(node*2+1, mid+1, right, ind, x);
	tree[node]=tree[node*2]+tree[node*2+1];
}

int sum(int node, int left, int right, int begin, int end) {
	if (end<left || right<begin) return 0;
	if (begin<=left && right<=end) return tree[node];
	int mid=(left+right)/2;
	int leq=sum(node*2, left, mid, begin, end);
	int riq=sum(node*2+1, mid+1, right, begin, end);
	return leq+riq;
}

int find(int x) {
	int left=0, right=1e6;
	int ret;
	while (left<=right) {
		int mid=(left+right)/2;
		int tmp=sum(1, 0, 1e6, 0, mid);
		if (tmp>=x) {
			ret=mid;
			right=mid-1;
		}
		else left=mid+1;
	}
	return ret;
}

int main() {
	init_code();

	int th=(int)ceil(log2(1e6+1));
	th=(1<<(th+1));
	tree=vector<int>(th, 0);
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a==1) {
			int b;
			cin >> b;
			int tmp=find(b);
			if (tmp!=0) {
				cout << tmp << '\n';
				upd(1, 0, 1e6, tmp, -1);
			}
		}
		else {
			int b, c;
			cin >> b >> c;
			upd(1, 0, 1e6, b, c);
		}
		/*cout << "sum is ";
		for (int i=0; i<5; i++) {
			cout << sum(1, 0, 1e6, i, i) << ' ';
		}
		cout << '\n';*/
	}

	return 0;
}
