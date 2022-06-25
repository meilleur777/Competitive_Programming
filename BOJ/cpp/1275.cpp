#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

vector<int> A;
vector<ll> tree;

void update(int index, ll x) {
	for (; index < tree.size(); index += (index & -index)) {
		tree[index] += x;
	}
}

ll sum(int index) {
	ll ret = 0;
	for (; index > 0; index &= index - 1) {
		ret += tree[index];
	}
	return ret;
}

ll query1(int start, int end) {
	return sum(end) - sum(start - 1);
}

void query2(int a, ll b) {
	ll temp = sum(a) - sum(a - 1);
	temp = b - temp;
	update(a, temp);	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, Q;
	cin >> N >> Q;
	
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}	
	
	tree.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		update(i, A[i - 1]);
	}
	
	while (Q--) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		
		if (x > y) swap(x, y);
		
		cout << query1(x, y) << '\n';
		query2(a, b);
	}
}

