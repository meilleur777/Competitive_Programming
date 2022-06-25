#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*Topological Sorting
Indegree의 수가 0인 노드들을 순서의 제약 없이 출력한다.
출력한 노드의 Outdegree를 탐색하여 그 노드들의 Indegree를 줄인다. 
Indegree가 0이라면 출력할 노드들에 포함시킨다. 

순서를 정하는 것이 불가능한 경우에 대한 판단이 필요하다.
그래프에서 사이클이 존재하는 경우, 즉 출력할 노드의 수가 N개 이하일 때 0을 출력한다. 
*/

queue<int> q;
int Indegree[1001] = { 0 };
vector<int> answer, Outdegree[1001];

int main() {
	int N, M, num = 0; scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int num; scanf("%d", &num);
		int a, b; scanf("%d", &a);
		for (int j = 0; j < num - 1; j++) {
			scanf("%d", &b);
			Outdegree[a].push_back(b);
			Indegree[b]++;
			a = b; 
		}
	}
	
	for (int i = 1; i <= N; i++) if (!Indegree[i]) q.push(i);
	
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (auto i : Outdegree[t]) {
			Indegree[i]--;
			if (!Indegree[i]) q.push(i);
		}
		num++; 
		answer.push_back(t);
	}
	
	if (num != N) printf("0\n");
	else for (auto i : answer) printf("%d\n", i);
}

