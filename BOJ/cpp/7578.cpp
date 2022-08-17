#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<int> c(1e6+1);
	rep(i, n) {
		c[b[i]]=i;
	}
	vector<int> d(n);
	rep(i, n) {
		d[i]=c[a[i]];
	}

	int treeheight=ceil(log2(n))+1;
	int treesize=(1<<treeheight);
	vector<int> tree(treesize, 0);
	ll ans=0;

	function<int(int, int, int, int, int)> sum=[&](int node, int start, int end, int left, int right) {
		if (end<left || right<start) return 0;
		if (left<=start && end<=right) return tree[node];
		int mid=(start+end)/2;
		int leftsum=sum(node*2+1, start, mid, left, right);
		int rightsum=sum(node*2+2, mid+1, end, left, right);
		return leftsum+rightsum;
	};
	function<void(int, int, int, int)> update=[&](int node, int start, int end, int index) {
		if (index<start || end<index) return ;
		if (index==start && start==end) {
			tree[node]++;
			return;
		}
		int mid=(start+end)/2;
		update(node*2+1, start, mid, index);
		update(node*2+2, mid+1, end, index);
		 tree[node]=tree[node*2+1]+tree[node*2+2];
	};

	for (int i=0; i<n; i++) {
		ans+=sum(0, 0, n-1, d[i]+1, n-1);
		update(0, 0, n-1, d[i]);
	}
	cout << ans;

	return 0;
}
