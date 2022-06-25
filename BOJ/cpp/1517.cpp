#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> tree;
vector<pair<int, int> > A;

ll getSum(int node, int left, int right, int begin, int end) {
	if (end < left || right < begin) return 0;
	if (begin <= left && right <= end) return tree[node];
	
	int mid = (left + right) / 2;
	ll leftSum = getSum(node * 2 + 1, left, mid, begin, end);
	ll rightSum = getSum(node * 2 + 2, mid + 1, right, begin, end);
	return leftSum + rightSum;
}

void update(int node, int left, int right, int index) {
	if (index < left || right < index) return;
	
	tree[node]++;
	if (left != right) {
		int mid = (left + right) / 2;
		update(node * 2 + 1, left, mid, index);
		update(node * 2 + 2, mid + 1, right, index);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		A.push_back({ a, i });	
	}	
	sort(A.begin(), A.end());
	
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	tree.resize(treeSize);
	fill_n(tree.begin(), tree.size(), 0);
	
	ll result = 0;
	for (int i = 0; i < N; i++) {
		result += getSum(0, 0, N - 1, A[i].second + 1, N - 1);
		update(0, 0, N - 1, A[i].second);
	}
	cout << result << '\n';
}

