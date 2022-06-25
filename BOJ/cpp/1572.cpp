#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, K;
vector<int> A;
vector<ll> tree;

void update(int index, int x) {
	for (; index < tree.size(); index += (index & -index)) {
		tree[index] += x;
	}
}

ll query() {
	int result = 0;
	int target = (K + 1) / 2;
	
	for (int i = 16; i >= 0; i--) {
		int up = (1 << i) + result;
		if (up < tree.size() && tree[up] < target) {
			target -= tree[up];
			result += (1 << i);
		}
	}
	return result + 1;	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	A.resize(N);
	tree.resize((1 << 16) + 2);
	
	ll result = 0;	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		update(A[i] + 1, 1);
		if (i < K - 1) continue;
		result += query() - 1;
		update(A[i - K + 1] + 1, -1);
 	}
	cout << result << '\n';
}

