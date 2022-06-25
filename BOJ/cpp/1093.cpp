#include <math.h>
#include <vector>
#include <limits.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int NEGINF = INT_MIN;

vector<int> maxTree;
int value[33], price[33];
vector<pair<int, int> > A1, A2;

/*오답 이유 : pair에서 lower_bound를 사용할 때 default로 first를 첫 기준으로 사용한다는 것은 알았으나,
second를 다음 기준으로 사용한다는 것을 알지 못해 second에 아무 값이나 넣어 놓았는데, first가 같으면
second를 기준으로 사용한다고 한다. 따라서 second에 NEGiNF를 넣어 해결했다.*/

bool compare(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

void getAll(int left, int right, int currentValue, int money, vector<pair<int, int> >& result) {
	if (left == right) {
		result.push_back({ currentValue, money });
		return;
	}
	getAll(left + 1, right, currentValue, money, result);
	getAll(left + 1, right, currentValue + value[left], money - price[left], result);
}

int getMax(int node, int left, int right, int begin, int end) {
	if (end < left || right < begin) return NEGINF;
	if (begin <= left && right <= end) return maxTree[node];
	
	int mid = (left + right) / 2;
	int leftMax = getMax(node * 2 + 1, left, mid, begin, end);
	int rightMax = getMax(node * 2 + 2, mid + 1, right, begin, end);
	return max(leftMax, rightMax);
}

int makeTree(int node, int left, int right) {
	if (left == right) return maxTree[node] = A2[left].second;
	
	int mid = (left + right) / 2;
	int leftMax = makeTree(node * 2 + 1, left, mid);
	int rightMax = makeTree(node * 2 + 2, mid + 1, right);
	return maxTree[node] = max(leftMax, rightMax);
}
	
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, K, M, priceSum = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> price[i];
	for (int i = 0; i < N; i++) cin >> value[i];
	cin >> K >> M;
	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		priceSum += price[x];
	}
	
	getAll(0, N / 2, 0, 0, A1); 
	getAll(N / 2, N, 0, 0, A2); 
	sort(A2.begin(), A2.end(), compare);
	
	int treeHeight = (int)ceil(log2(A2.size()));
	int treeSize = (1 << (treeHeight + 1));
	maxTree.resize(treeSize + 10);
	makeTree(0, 0, A2.size() - 1);
	
	int result = NEGINF;
	int A1size = A1.size(), A2size = A2.size();	
	for (auto i : A1) {
		int temp = lower_bound(A2.begin(), A2.end(), make_pair(K - i.first, NEGINF)) - A2.begin();
		if (temp < A2size) result = max(result, i.second + getMax(0, 0, A2size - 1, temp, A2size - 1));
	}
	
	if (result != NEGINF) {
		result = min(result + priceSum, 0);	
		cout << -result << '\n';
	}
	else cout << -1 << '\n';
}

