#include <stdio.h>
#include <queue>
#define min(a, b) MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;

typedef struct {
	int row;
	int col;
	bool chance;
} node;

int rdi[4] = { 1, -1, 0, 0 };
int cdi[4] = { 0, 0, 1, -1 };
int map[1001][1001];
int vis[2][1001][1001] = { 0 };

int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	/*BFS로 경로를 탐색한다. try 구조체를 선언하여 현재 노드의 좌표상 위치,
	벽 부수기 기회, 이동 거리를 담는다. 벽 부수기라는 변수가 있기 때문에 탐색에 주의가 필요하다.
	무작정 방문 기록이 있다고 해서 지나치면 안된다. 따라서 방문 기록을 pair로 구성하는데, 
	한 가지는 벽 부수기 기회를 소진한 후 방문하는 것이고, 나머지는 벽 부수기 기회를 가지고 방문하는 것이다.*/
	
	/*vis[0]은 부수기 기회를 소진한 후, vis[1]은 부수기 기회를 가진 채로 방문*/
	vis[1][0][0] = 1;	
	queue<node> q;
	node start = { 0, 0, true };
	q.push(start);
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int trow = cur.row + rdi[i];
			int tcol = cur.col + cdi[i];
			if (trow >= 0 && trow < N && tcol >= 0 && tcol < M) {
				if (cur.chance) {
					if (!map[trow][tcol] && !vis[1][trow][tcol]) {
						vis[1][trow][tcol] = vis[1][cur.row][cur.col] + 1;
						node temp = { trow, tcol, true };
						q.push(temp);
					}
					else if (map[trow][tcol] && !vis[0][trow][tcol]) {
						vis[0][trow][tcol] = vis[1][cur.row][cur.col] + 1;
						node temp = { trow, tcol, false };
						q.push(temp); 
					}
				}
				else {
					if (!map[trow][tcol] && !vis[0][trow][tcol]) {
							vis[0][trow][tcol] = vis[0][cur.row][cur.col] + 1;
							node temp = { trow, tcol, false };
							q.push(temp);
					}
				}
			}
		}
	}
	int a = vis[0][N - 1][M - 1], b = vis[1][N - 1][M - 1];
	if (a && b) printf("%d\n", min(a, b));
	else if (!a && b) printf("%d\n", b);
	else if (a && !b) printf("%d\n", a);
	else printf("-1\n");
}

