#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int TC = 1;
	while (1) {
		int n, m; scanf("%d %d", &n, &m);
		if (!n && !m) break;
		
		vector<int> edges[501];
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		
		int count = 0;
		bool visit[501] = { false };
		
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				bool flag = false; 
				visit[i] = true;
				queue<int> q;
				q.push(i);	
				while (!q.empty()) {
					int check = 0;
					int temp = q.front(); q.pop();
					
					for (auto j : edges[temp]) {
						if (visit[j]) {
							check++;
							if (check == 2) flag = true;
						}
						else {
							visit[j] = true;
							q.push(j);
						}
					}
				}
				if (!flag) count++;
 			}
		}
		
		printf("Case %d: ", TC++);
		if (!count) printf("No trees.\n");
		else if (count == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", count);
	}
}

