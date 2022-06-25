#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

vector<int> A;
vector<ll> tree;

ll makeTree(int node, int left, int right) {
	if (left == right) return tree[node] = A[left];
	
	int mid = (left + right) / 2;
	ll leftMul = makeTree(node * 2, left, mid);
	ll rightMul = makeTree(node * 2 + 1, mid + 1, right);
	return tree[node] = leftMul * rightMul % MOD; 
}

ll getMul(int node, int left, int right, int begin, int end) {
	if (end < left || right < begin) return 1;
	if (begin <= left && right <= end) return tree[node];
	
	int mid = (left + right) / 2;
	ll leftMul = getMul(node * 2, left, mid, begin, end);
	ll rightMul = getMul(node * 2 + 1, mid + 1, right, begin, end);
	return leftMul * rightMul % MOD;
}

ll update(int node, int left, int right, int index, ll x) {
	if (index < left || right < index) return tree[node];
	if (left == right) return tree[node] = x;
	
	int mid = (left + right) / 2;
	ll leftMul = update(node * 2, left, mid, index, x);
	ll rightMul = update(node * 2 + 1, mid + 1, right, index, x);
	return tree[node] = leftMul * rightMul % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M, K; cin >> N >> M >> K;
	M += K; A.resize(N + 1);
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	tree.resize(treeSize);
	makeTree(1, 1, N);
	
	while (M--)	{
		ll a, b, c; cin >> a >> b >> c;
		switch (a) {
			case 1: update(1, 1, N, b, c); break;
			case 2: cout << getMul(1, 1, N, b, c) << '\n';
		}
	}
}

