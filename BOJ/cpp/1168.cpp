#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
vector<int> tree;

void update(int index, int x) {
	for (; index < tree.size(); index += (index & -index)) {
		tree[index] += x;
	}
}

int start;

int find(int target) {
	int result = 0;
	
	for (int i = start; i >= 0; i--) {
		int temp = result + (1 << i);
		if (temp < tree.size() && tree[temp] < target) {
			target -= tree[temp];
			result += (1 << i);
		}
	}
	
	return result + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	
	tree.resize(N + 1);
	start = (int)floor(log2(tree.size()));
	for (int i = 1; i <= N; i++) {
		update(i, 1);
	}
	
	int count = 0;
	int target = 1;
	
	cout << '<';
	while (count < N) {
		int size = N - count;
		target += K - 1;
		
		if (target % size) {
			target %= size;
		}
		else target = size;
		
		count++;
				
		int temp = find(target);
		update(temp, -1);
				
		cout << temp;
		if (count != N) cout << ", ";
	}
	cout << '>';
}

