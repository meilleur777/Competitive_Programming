#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

vector<vector<int>> tree;

void update(int node, int start, int end, int index, int value) {
	if (index<start || end<index) return;
	tree[node].push_back(value);
	if (start!=end) {
		int mid=(start+end)/2;
		update(node*2+1, start, mid, index, value);
		update(node*2+2, mid+1, end, index, value);
	}
}

int query(int node, int start, int end, int left, int right, int value) {
	if (right<start || end<left) return 0;
	if (left<=start && end<=right) {
		return tree[node].end()-upper_bound(tree[node].begin(), tree[node].end(), value);
	}
	int mid=(start+end)/2;
	int lquery=query(node*2+1, start, mid, left, right, value);
	int rquery=query(node*2+2, mid+1, end, left, right, value);
	return lquery+rquery;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
    int n;
    cin >> n;

    int treeheight=ceil(log2(n))+1;
    int treesize=1<<treeheight;
    tree=vector<vector<int>>(treesize);

    rep(i, n) {
        int a;
        cin >> a;
        update(0, 0, n-1, i, a);
    }
    for (auto& v:tree) {
    	sort(v.begin(), v.end());
    }

    int m;
	cin >> m;
	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		cout << query(0, 0, n-1, i-1, j-1, k) << '\n';
	}

    return 0;
}
