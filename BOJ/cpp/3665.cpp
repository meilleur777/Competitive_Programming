#include <stdio.h>
#include <queue>
using namespace std;

/*Topological Sorting 
팀 1, 2, 3, 4가 지난 해 각 팀의 번호를 등수로 기록했다고 하자.
팀 1은 팀 2, 3, 4보다 우선하고, 팀 2는 팀 3, 4보다 우선하고, 팀 3은 팀 4보다 우선한다.
따라서 이것은 Directed Graph를 Topological sorting한것으로 볼 수 있다.
또한 두 팀간의 등수 변화는 두 노드를 있는 간선의 방향이 바뀐 것으로 볼 수 있다.

임의의 팀에서 그 팀보다 등수가 높은 모든 팀 방향으로 간선을 연결해준 후,
방향이 바뀐 간선들을 수정해준다. 그 후 Topological Sorting한다.

확실한 순위를 만들 수 없는 경우 = 출력 후보가 여러 팀인 경우 
일관성이 없는 경우 = 사이클이 생기는 경우*/

/*오답 이유 -> 간선의 방향을 바꾸는 부분에서 오타*/

/*두 개 이상의 노드가 후보가 되는 경우는 존재하지 않음
1. 각각의 노드에 대해서 Indegree 수는 연속적인 정수 배열로 존재한다. (순위가 높은 순부터 
n-1, n-2, n-3..., 이미 출력한 노드는 제외하고) 또한 간선의 방향을 바꾸는 과정에서 그 성질은
유지된다. (순위가 바뀐 모든 팀의 목록 제공) 
2. 각각의 시행마다 모든 정점(출력한 노드, 현재 노드 제외)의 Indegree가 항상 1씩 줄어든다. 
하나의 정점에서 다른 정점으로 가는 edge는 항상 하나이기 때문이다. 
=> 따라서 동시에 0이 되는 노드가 두 개 이상일 수 없다.

옳은 증명인지는 확실치않다 ㅠㅠ 
그러나 ?을 제외하고 제출해도 정답인 것을 보면 참인 명제인듯 하다.*/

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m;
		queue<int> q;
		bool edge[501][501] = { false }; 
		int Indegree[501] = { 0 }, result[501], count = 0;
		int rank[501];	/*rank[a] = b -> 작년에 b팀이 a등을 함*/ 
		
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &rank[i]);
		
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) edge[rank[j]][rank[i]] = true;
			Indegree[rank[i]] = n - i;
		}
		
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			if (edge[a][b]) {
				edge[a][b] = false; edge[b][a] = true;
				Indegree[a]++; Indegree[b]--;
			}
			else {
				edge[b][a] = false; edge[a][b] = true;
				Indegree[b]++; Indegree[a]--;
			}
		} 
		
		for (int i = 1; i <= n; i++) if (!Indegree[i]) q.push(i);
		while (!q.empty()) {
			int t = q.front(); q.pop();
			for (int i = 1; i <= n; i++) {
				if (edge[t][i]) {
					Indegree[i]--;
					if (!Indegree[i]) q.push(i);
				}
			}
			result[count++] = t;
		}
		
		if (count < n) printf("IMPOSSIBLE\n");
		else {
			for (int i = n - 1; i >= 0; i--) printf("%d ", result[i]);
			printf("\n");
		}
	}
}

