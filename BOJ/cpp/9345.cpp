#include <math.h>
#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;

int N;

struct segmentTree {
	int treeSize;
	vector<int> tree;
	
	segmentTree(vector<int>& array) {
		int treeHeight = (int)ceil(log2(array.size()));
		treeSize = (1 << (treeHeight + 1));
		tree.resize(treeSize);
		makeTree(array, 0, 0, array.size() - 1);
	}
	
	int makeTree(vector<int>& array, int node, int left, int right) {
		if (left == right) return tree[node] = array[left];
		
		int mid = (left + right) / 2;
		int leftMin = makeTree(array, node * 2 + 1, left, mid);
		int rightMin = makeTree(array, node * 2 + 2, mid + 1, right);
		return tree[node] = min(leftMin, rightMin);
	}
	
	int query(int node, int left, int right, int begin, int end) {
		if (end < left || right < begin) return INT_MAX;
		if (begin <= left && right <= end) return tree[node];
		
		int mid = (left + right) / 2;
		int leftMin = query(node * 2 + 1, left, mid, begin, end);
		int rightMin = query(node * 2 + 2, mid + 1, right, begin, end);
		return min(leftMin, rightMin);
	}
	
	int update(int node, int left, int right, int index, int x) {
		if (index < left || right < index) return tree[node];
		if (left == right) return tree[node] = x;
		
		int mid = (left + right) / 2;
		int leftMin = update(node * 2 + 1, left, mid, index, x);
		int rightMin = update(node * 2 + 2, mid + 1, right, index, x);
		return tree[node] = min(leftMin, rightMin);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> N >> K;
		
		vector<int> array(N);
		for (int i = 0; i < N; i++) array[i] = i;
		segmentTree minTree(array);
		for (int& i : array) i *= -1;
		segmentTree maxTree(array);
				
		while (K--) {
			int Q, A, B;
			cin >> Q >> A >> B;
			
			if (!Q) {
				int getA = minTree.query(0, 0, N - 1, A, A);
				int getB = minTree.query(0, 0, N - 1, B, B);
				
				minTree.update(0, 0, N - 1, A, getB);
				minTree.update(0, 0, N - 1, B, getA);
				maxTree.update(0, 0, N - 1, A, -getB);
				maxTree.update(0, 0, N - 1, B, -getA);
			}
			else {
				bool a = (A == minTree.query(0, 0, N - 1, A, B));
				bool b = (B == -maxTree.query(0, 0, N - 1, A, B));
				if (a && b) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}

