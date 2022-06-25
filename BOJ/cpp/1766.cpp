#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
자식이 없으면 출력, 자식이 없는 노드가 여러 개이면 수가 작은 것부터 출력
->priority queue를 사용하여 구현, 자식이 없는 노드들을 출력함과 동시에
그 노드의 부모들의 indegree--, if (!indegree) -> pq.push 
*/

int child[32001] = { 0 };
vector<int> v[32001];
priority_queue<int, vector<int>, greater<int> > q; 

int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int A, B; scanf("%d %d", &A, &B);
		v[A].push_back(B);
		child[B]++;	
	}
	for (int i = 1; i <= N; i++) if (!child[i]) q.push(i);
	while (!q.empty()) {
		int node = q.top();
		q.pop();
		for (auto i : v[node]) {
			child[i]--;
			if (!child[i]) q.push(i);
		}
		printf("%d ", node);
	}
}
