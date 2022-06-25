#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

vector<ll> A;
vector<ll> tree;

ll makeSegmentTree(int node, int left, int right) {
	if (left == right) return tree[node] = A[left];
	
	int mid = (left + right) / 2;
	ll leftSum = makeSegmentTree(node * 2, left, mid);
	ll rightSum = makeSegmentTree(node * 2 + 1, mid + 1, right);
	return tree[node] = leftSum + rightSum;
}

ll getSum(int node, int left, int right, int begin, int end) {
	if (end < left || right < begin) return 0;
	if (begin <= left && right <= end) return tree[node]; 
	
	int mid = (left + right) / 2;
	ll leftSum = getSum(node * 2, left, mid, begin, end);
	ll rightSum = getSum(node * 2 + 1, mid + 1, right, begin, end);
	return leftSum + rightSum;
}

void update(int node, int left, int right, int index, ll diff) {
	if (index < left || index > right) return;
	tree[node] += diff;
	
	if (left != right) {
		int mid = (left + right) / 2;
		update(node * 2, left, mid, index, diff);
		update(node * 2 + 1, mid + 1, right, index, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M, K; cin >> N >> M >> K;
	A.resize(N + 1);
	for (int i = 1; i <= N; i++) cin >> A[i];	
	
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	tree.resize(treeSize);
	makeSegmentTree(1, 1, N);
	
	for (int i = 0; i < M + K; i++) {
		ll a, b, c; cin >> a >> b >> c;
		switch (a) {
			case 1: {
				ll diff = c - A[b]; A[b] = c;
				update(1, 1, N, b, diff); 
				break;
			}
			case 2: cout << getSum(1, 1, N, b, c) << '\n';
		}
	}
}

