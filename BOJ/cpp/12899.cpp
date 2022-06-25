#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> tree;

void add(int index, int x) {
	for (; index < tree.size(); index += (index & -index)) {
		tree[index] += x;
	}
}

int lowerbound(int x) {
	int result = 0;
	int max = (int)floor(log2(tree.size()));
	
	for (int i = max; i >= 0; i--) {
		int temp = result + (1 << i);
		if (temp < tree.size() && tree[temp] < x) {
			x -= tree[temp];
			result += 1 << i;
		}
	}
	return result + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	
	tree.resize(2000001);
	fill(tree.begin(), tree.end(), 0);
	int temp = (int)ceil(log2(tree.size()));
	
	for (int i = 0; i < N; i++) {
		int T, X;
		cin >> T >> X;
		
		switch (T) {
			case 1:
				add(X, 1);
				break;
			case 2:
				int temp = lowerbound(X);
				cout << temp << '\n';
				add(temp, -1);
				
		}
	}	
}

