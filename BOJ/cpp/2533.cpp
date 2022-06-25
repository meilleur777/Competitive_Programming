#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;

/*가능한 얼리 어답터의 조합 = 2^N, 선택 or 선택 안함
모든 얼리 어답터가 아닌 정점은 그 인접 노드가 모두 얼리 어답터여야 한다.
어떤 노드를 루트로 잡고, 얼리 어답터 여부를 정한다. 만일 얼리 어답터로 한다면, 인접 노드들의
얼리 어답터 여부는 상관없다. 그러나 얼리 어답터가 아니라고 한다면, 인접 노드 모두가 얼리 어답터가
되어야 한다. 이때 어떤 노드의 얼리 어답터 여부를 알기 위해 필요한 것은 바로 직전 노드의 
얼리 어답터 여부라는 것을 알 수 있다.*/

int cache[2][1000002]; 
vector<int> edges[1000002], tree[1000002];

/*현재 노드가 current이고, early의 상태일 때, 자신을 루트로 하는 서브트리에 필요한
최소 얼리 어답터의 수 반환*/
int solve(int current, int early) {
	int& ret = cache[early][current];
	if (ret != -1) return ret;
	
	/*현재 노드가 얼리 어답터라면 직전 노드의 상태는 결정되지 않는다.*/
	if (early) {
		ret = 1;
		for (int i : tree[current]) ret += min(solve(i, 1), solve(i, 0));
	}
	/*현재 노드가 얼리 어답터가 아니라면 직전 노드는 얼리 어답터였음을 알 수 있다.*/
	else {
		ret = 0;
		for (int i : tree[current]) ret += solve(i, 1);
	}
	return ret;
}

bool visit[1000002] = { false };

/*단방향 트리, 부모 -> 자식*/
void makeTree(int root) {
	visit[root] = true;
	for (int i : edges[root]) {
		if (visit[i]) continue;
		tree[root].push_back(i);
		makeTree(i);
	}
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
	
	int N; cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	makeTree(1);
	int result = min(solve(1, 1), solve(1, 0));
	cout << result << '\n';
}

