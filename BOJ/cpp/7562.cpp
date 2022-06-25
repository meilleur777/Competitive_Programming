#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> p;
int rdi[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int cdi[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int I, A, B; 
		scanf("%d %d %d", &I, &A, &B);
		p start = make_pair(A, B);
		scanf("%d %d", &A, &B);
		p end = make_pair(A, B);
		queue<p> q;
		q.push(start);
		int visit[301][301] = { 0 };		
		visit[start.first][start.second] = 1;
		
		while (!q.empty()) {
			int row = q.front().first;
			int col = q.front().second;
			if (row == end.first && col == end.second) break;
			q.pop();
			
			for (int i = 0; i < 8; i++) {
				int trow = row + rdi[i], tcol = col + cdi[i];
				if (trow >= 0 && trow < I && tcol >= 0 && tcol < I && !visit[trow][tcol]) {
					visit[trow][tcol] = visit[row][col] + 1;
					q.push(make_pair(trow, tcol));
				}
			}
		}
		printf("%d\n", visit[end.first][end.second] - 1);
	}
}

