#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

/*Bellman-Ford Algorithm*/

typedef pair<int, int> p;

int main() {
	int TC; scanf("%d", &TC);
	while (TC--) {
		vector<p> edges[501];
		int N, M, W; scanf("%d %d %d", &N, &M, &W);
		for (int i = 0; i < M; i++) {
			int S, E, T; scanf("%d %d %d", &S, &E, &T);
			edges[S].push_back(make_pair(E, T));
			edges[E].push_back(make_pair(S, T));
		}
		for (int i = 0; i < W; i++) {
			int S, E, T; scanf("%d %d %d", &S, &E, &T);
			edges[S].push_back(make_pair(E, -1 * T));
		}
		
		int d[501];
		memset(d, 0x7F, sizeof(d));
		int temp = 1;
		d[1] = 0;
		
		for (int i = 0; i < N - 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				for (auto k : edges[j]) {
					if (d[k.first] > d[j] + k.second) {
						d[k.first] = d[j] + k.second;
					}
				}
			}
		}
		
		bool flag = false;
		for (int i = 1; i < N + 1; i++) {
			if (flag) break;
			for (auto j : edges[i]) {
				if (d[j.first] > d[i] + j.second) {
					flag = true;				
				}
			}
		}
		
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
}

