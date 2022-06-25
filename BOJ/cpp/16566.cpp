#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*철수가 낼 카드의 수가 주어졌을 때, 그 카드보다 숫자가 큰 카드들 중 가장 작은 카드를 찾아야 한다.
간단해 보였으나, 카드 개수가 4백만개이다. Union-Find algorithm을 사용해 upper_bound의 부모를 
내는 것으로 하면 되지 않을까? 단 merge할 때 index가 큰 것을 가리키도록 해야 한다.*/

vector<int> minsu;
int parent[4000001];	/*parent[a] : minsu[a]의 부모*/

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M, K; cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		minsu.push_back(x);
	}	
	sort(minsu.begin(), minsu.end());
	
	for (int i = 0; i < M; i++) parent[i] = i;
	for (int i = 0; i < K; i++) {
		int x; cin >> x;
		int temp = upper_bound(minsu.begin(), minsu.end(), x) - minsu.begin();
		int tempar = find(temp);
		merge(tempar, tempar + 1);
		cout << minsu[tempar] << '\n';
	}
}

