#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

struct segmentTree {
	bool even;
	vector<int> tree;
	
	segmentTree(const vector<int>& array, bool flag) {
		even = flag;
		int treeHeight = (int)ceil(log2(array.size()));
		tree.resize(1 << (treeHeight + 1));
		makeTree(array, 0, 0, array.size() - 1);
	}
	
	int makeTree(const vector<int>& array, int node, int left, int right) {
		if (left == right) return tree[node] = (array[left] + even) % 2;
		
		int mid = (left + right) / 2;
		int leftSum = makeTree(array, node * 2 + 1, left, mid);
		int rightSum = makeTree(array, node * 2 + 2, mid + 1, right);
		return tree[node] = leftSum + rightSum;
	}
	
	int getSum(int node, int left, int right, int begin, int end) {
		if (end < left || right < begin) return 0;
		if (begin <= left && right <= end) return tree[node];
		
		int mid = (left + right) / 2;
		int leftSum = getSum(node * 2 + 1, left, mid, begin, end);
		int rightSum = getSum(node * 2 + 2, mid + 1, right, begin, end);
		return leftSum + rightSum;
	}
	
	int update(int node, int left, int right, int index, int x) {
		if (index < left || right < index) return tree[node];
		if (left == right) return tree[node] = x;
		
		int mid = (left + right) / 2;
		int leftSum = update(node * 2 + 1, left, mid, index, x);
		int rightSum = update(node * 2 + 2, mid + 1, right, index, x);	
		return tree[node] = leftSum + rightSum;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	int N, M, a, b, c; 
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> M;
	
	segmentTree evenTree(A, true);
	segmentTree oddTree(A, false);
			
	while (M--) {
		cin >> a >> b >> c;
		switch (a) {
			case 1: evenTree.update(0, 0, N - 1, b - 1, (c + 1) % 2); 
					oddTree.update(0, 0, N - 1, b - 1, c % 2); break;
			case 2: cout << evenTree.getSum(0, 0, N - 1, b - 1, c - 1) << '\n'; break;
			case 3: cout << oddTree.getSum(0, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}
}

