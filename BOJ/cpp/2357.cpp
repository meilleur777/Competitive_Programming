#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;

vector<int> A;
vector<int> minTree, maxTree;

int getMin(int node, int left, int right, int begin, int end) {
	if (end < left || right < begin) return INF;
	if (begin <= left && right <= end) return minTree[node];
	
	int mid = (left + right) / 2;
	int leftMin = getMin(node * 2, left, mid, begin, end);
	int rightMin = getMin(node * 2 + 1, mid + 1, right, begin, end);
	return min(leftMin, rightMin);
}

int getMax(int node, int left, int right, int begin, int end) {
	if (end < left || right < begin) return 0;
	if (begin <= left && right <= end) return maxTree[node];
	
	int mid = (left + right) / 2;
	int leftMax = getMax(node * 2, left, mid, begin, end);
	int rightMax = getMax(node * 2 + 1, mid + 1, right, begin, end);
	return max(leftMax, rightMax);
}

int makeMinTree(int node, int left, int right) {
	if (left == right) return minTree[node] = A[left];
	
	int mid = (left + right) / 2;
	int leftMin = makeMinTree(node * 2, left, mid);
	int rightMin = makeMinTree(node * 2 + 1, mid + 1, right);
	return minTree[node] = min(leftMin, rightMin);
}

int makeMaxTree(int node, int left, int right) {
	if (left == right) return maxTree[node] = A[left];
	
	int mid = (left + right) / 2;
	int leftMax = makeMaxTree(node * 2, left, mid);
	int rightMax = makeMaxTree(node * 2 + 1, mid + 1, right);
	return maxTree[node] = max(leftMax, rightMax);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M; cin >> N >> M;
	A.resize(N + 1);
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	minTree.resize(treeSize), makeMinTree(1, 1, N);
	maxTree.resize(treeSize), makeMaxTree(1, 1, N);
	
	while (M--) {
		int a, b; cin >> a >> b;
		cout << getMin(1, 1, N, a, b) << ' ' << getMax(1, 1, N, a, b) << '\n';
	}
}

