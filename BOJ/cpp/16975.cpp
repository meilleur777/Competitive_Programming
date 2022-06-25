#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

vector<ll> tree;

ll sum(int index) {
	ll ret = 0;
	for (; index > 0; index &= (index - 1)) {
		ret += tree[index];
	}
	return ret;
}

void update(int index, ll x) {
	for (; index < tree.size(); index += (index & -index)) {
		tree[index] += x;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	
	tree.resize(N + 1);
	
	ll num1, num2;
	cin >> num1;
	update(1, num1);
	for (int i = 2; i <= N; i++) {
		cin >> num2;
		update(i, num2 - num1);
		num1 = num2;
	}	
	
	int M;
	cin >> M;
	while (M--) {
		int order;
		cin >> order;
		
		switch (order) {
			case 1:
				ll i, j, k;
				cin >> i >> j >> k;
				update(i, k);
				update(j + 1, -k);
				break;
			case 2:
				int x; 
				cin >> x;
				cout << sum(x) << '\n';
		}
	}
}

