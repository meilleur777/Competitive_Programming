#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

vector<int> tree;

int find(int node, int start, int end, int value) {
	if (start==end) return start;
	int mid=(start+end)/2;
	if (tree[node*2+1]+value<=mid-start) return find(node*2+1, start, mid, value);
	else return find(node*2+2, mid+1, end, value-(mid-start+1-tree[node*2+1]));
}

void update(int node, int start, int end, int index) {
	if (index>end || index<start) return;
	if (start==end && start==index) {
		tree[node]++;
		return;
	}
	int mid=(start+end)/2;
	update(node*2+1, start, mid, index);
	update(node*2+2, mid+1, end, index);
	tree[node]=tree[node*2+1]+tree[node*2+2];
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;

	int treeheight=ceil(log2(n))+1;
	int treesize=1<<treeheight;
	tree=vector<int>(treesize, 0);

	vector<int> ans(n);
	rep(i, n) {
		int a;
		cin >> a;
		int t=find(0, 0, n-1, a);
		ans[t]=i;
		update(0, 0, n-1, t);
	}
	for (auto i:ans) {
		cout << i+1 << '\n';
	}

	return 0;
}
