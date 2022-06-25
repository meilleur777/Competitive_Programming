#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

vector<vector<int> > child;
vector<int> tree;
vector<int> depth;
vector<int> preorder;
vector<int> startTrip;

void calDepth(int root, int d) {
	depth[root] = d;
	for (auto i : child[root]) calDepth(i, d + 1);
}

void traverse(int root) {
	startTrip[root] = preorder.size();
	preorder.push_back(root);
	for (auto i : child[root]) {
		traverse(i);
		preorder.push_back(root);
	}
}

int getMin(int node, int left, int right, int begin, int end) {
	if (end < left || right < begin) return -1;
	if (begin <= left && right <= end) return tree[node];
	
	int mid = (left + right) / 2;
	int leftMin = getMin(node * 2 + 1, left, mid, begin, end);
	int rightMin = getMin(node * 2 + 2, mid + 1, right, begin, end);
	
	if (leftMin == -1) return rightMin;
	if (rightMin == -1) return leftMin;
	return (depth[leftMin] < depth[rightMin]) ? leftMin : rightMin;
	
}

int makeTree(int node, int left, int right) {
	if (left == right) return tree[node] = preorder[left];
	
	int mid = (left + right) / 2;
	int leftMin = makeTree(node * 2 + 1, left, mid);
	int rightMin = makeTree(node * 2 + 2, mid + 1, right);
	return tree[node] = (depth[leftMin] < depth[rightMin]) ? leftMin : rightMin;
}

void prepareTree() {
	int treeHeight = (int)ceil(log2(preorder.size()));
	int treeSize = (1 << (treeHeight + 1));
	tree.resize(treeSize);
	makeTree(0, 0, preorder.size() - 1);
}

int solve(int a, int b) {
	int begin = startTrip[a], end = startTrip[b];
	if (begin > end) begin = startTrip[b], end = startTrip[a];
	int ret = getMin(0, 0, preorder.size() - 1, begin, end);
	return depth[a] + depth[b] - 2 * depth[ret];
}

void clearVector() {
	child.clear();
	tree.clear();
	depth.clear();
	preorder.clear();
	startTrip.clear();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C;
	cin >> C;
	while (C--) {
		clearVector();
		
		int N, Q;
		cin >> N >> Q;
		
		child.resize(N);
		for (int i = 1; i < N; i++) {
			int x;
			cin >> x;
			child[x].push_back(i);
		}
			
		depth.resize(N);		
		calDepth(0, 0);
		startTrip.resize(N);
		traverse(0);
		prepareTree();
		
		while (Q--) {
			int a, b;
			cin >> a >> b;
			cout << solve(a, b) << '\n';
		}
	}	
}

