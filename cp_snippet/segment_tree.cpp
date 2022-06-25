vector<int> tree;

void upd(int node, int left, int right, int ind, int x) {
	if (ind<left || right<ind) return;
	if (left==right) {
		tree[node]=/*???*/
		return;
	}
	int mid=(left+right)/2;
	upd(node*2, left, mid, ind, x);
	upd(node*2+1, mid+1, right, ind, x);
	tree[node]=/*???*/
}

int query(int node, int left, int right, int begin, int end) {
	if (end<left || right<begin) return /*???*/;
	if (begin<=left && right<=end) return tree[node];
	int mid=(left+right)/2;
	int leq=query(node*2, left, mid, begin, end);
	int riq=query(node*2+1, mid+1, right, begin, end);
	return /*???*/
}

int th=(int)ceil(log2(/*???*/));
th=(1<<(th+1));
tree=vector<int>(th, 0);
