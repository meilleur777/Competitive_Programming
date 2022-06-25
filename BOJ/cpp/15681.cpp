#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

int childNum[100002];
vector<int> edges[100002];

/*root를 루트로 하는 서브트리의 노드 수 반환*/
int solve(int root) {
	int& ret = childNum[root];
	if (ret != -1) return ret;
	
	ret = 1;
	for (int i : edges[root]) {
		if (childNum[i] != -1) continue;
		ret += solve(i);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	memset(childNum, -1, sizeof(childNum));
	
	int N, R, Q;
	cin >> N >> R >> Q;
	for (int i = 1; i < N; i++) {
		int U, V;
		cin >> U >> V;
		edges[U].push_back(V);
		edges[V].push_back(U);
	}
	int temp = solve(R);	
	
	while (Q--) {
		int U; cin >> U;
		cout << childNum[U] << '\n';
	}
}

