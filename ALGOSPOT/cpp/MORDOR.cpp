#include <math.h>
#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;

/*range minimum query*/
struct RMQ {
	int n;
	vector<int> tree;
	RMQ(const vector<int>& array) {
		n = (int)ceil(log2(array.size()));
		tree.resize(1 << (n + 1));
		makeTree(array, 0, 0, array.size() - 1);		
	}
	
	int makeTree(const vector<int>& array, int node, int left, int right) {
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
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		int N, Q; cin >> N >> Q;
		vector<int> h(N);
		for (int i = 0; i < N; i++) cin >> h[i];
				
		RMQ minTree(h);
		for (int& i : h) i *= -1;
		RMQ maxTree(h);
		
		while (Q--) {
			int a, b; cin >> a >> b;
			cout << -maxTree.query(0, 0, N - 1, a, b) - minTree.query(0, 0, N - 1, a, b) << '\n';
		}		
	}	
}

