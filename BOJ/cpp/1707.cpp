#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	
	while (T--) {
		vector<int> edges[20001];
		int V, E; scanf("%d %d", &V, &E);
		for (int i = 0; i < E; i++) {
			int S, U; scanf("%d %d", &S, &U);
			edges[S].push_back(U);
			edges[U].push_back(S);
		}
		
		bool flag = false;		
		int visit[20001] = { 0 };	
		
		for (int j = 1; j <= V; j++) {
			if (flag) break;
			
			if (!visit[j]) {
				queue<int> q;
				q.push(j);	
				visit[j] = 1;
				
				while (!q.empty()) {
					int temp = q.front(); q.pop();
					for (auto i : edges[temp]) {
						if (!visit[i]) {
							int color = visit[temp] == 1 ? 2 : 1;
							visit[i] = color;
							q.push(i);
						}
						else if (visit[i] == visit[temp]) {
							flag = true;
							break;
						}
					}
				}
			}
		}
		
		if (flag) printf("NO\n");
		else printf("YES\n");
	}
}

